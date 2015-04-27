unsigned char LED_BCD[16] =
  { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e }; 

int data = 3;  
int rck  = 4;
int sck  = 5;

int pin_int = 2;

void setup() {         
  Serial.begin( 9600 );
  
  pinMode( data, OUTPUT );
  pinMode( rck,  OUTPUT );
  pinMode( sck,  OUTPUT );  
  
  digitalWrite( pin_int, HIGH );
  
  attachInterrupt( pin_int-2, interrupt_handler, RISING );
}

int pulse_counter = 0;

void interrupt_handler()
{
  pulse_counter = pulse_counter + 1;
}

unsigned long old_tick = 0;
unsigned long tick = 0;
unsigned long term = 0;

unsigned long value = 0;

int interval = 1000;

void loop() {
  if (old_tick == 0) {
    old_tick = millis();
    return;
  }
  
  tick = millis();
  
  term = term + tick - old_tick;
  
  if (term >= interval) {
    value = pulse_counter; // * term / interval;
    
    Serial.println( value );  
    
    term = 0;
    pulse_counter = 0;
  }
  
//  display_integer( value );
  
  delay(10);
  
  old_tick = tick;
}

void display_integer(int value)
{
  int d = value / 1000;
  display_number( 3, d, 0 );
  value = value - d * 1000;
  
  d = value / 100;
  display_number( 2, d, 0 );
  value = value - d * 100;
  
  d = value / 10;
  display_number( 1, d, 0 );
  value = value - d * 10;

  display_number( 0, value, 0 );
}

void display_number(byte no, byte value, byte set_dp_on)
{
  unsigned int HC_DISP = 0;
  unsigned int HC_LEDCODE;
  unsigned int HC_LEDCODE_temp = 0;
 
  if (value > 15) value = 0;
  
  HC_LEDCODE = LED_BCD[value]; 
  
  for (unsigned char i=0; i<8; ++i) {
     HC_LEDCODE_temp <<= 1;
     if (HC_LEDCODE&0x01) HC_LEDCODE_temp |= 0x01;
     HC_LEDCODE >>= 1;
  }

  if (set_dp_on)  HC_LEDCODE_temp &= 0xfe;
  HC_DISP = HC_LEDCODE_temp;
 
  switch(no) {
     case 0: HC_DISP |= 0x8000; break;
     case 1: HC_DISP |= 0x4000; break;
     case 2: HC_DISP |= 0x2000; break;
     case 3: HC_DISP |= 0x1000; break;
  }
 
  write_74HC595( HC_DISP );
}

void write_74HC595(unsigned int data_a) 
{
  digitalWrite( rck, LOW ); 
  digitalWrite( sck, LOW );

  for (byte look=0; look<16; ++look) {
    if (data_a&0x0001) digitalWrite( data, HIGH );
    else digitalWrite( data, LOW );
    
    digitalWrite( sck, HIGH );
    digitalWrite( sck, LOW );
    
    data_a >>= 1;
  }
  
  digitalWrite( rck, HIGH );
}

