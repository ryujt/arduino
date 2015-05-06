unsigned char LED_BCD[16] =
  { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e }; 

int data = 1;  
int rck  = 3;
int sck  = 4;

int pin_switch = 2;

int pin_buzzer = 0;

volatile int count = 0;

unsigned long old_tick;
unsigned long tick;

void setup() {
//  Serial.begin(9600);
  
  pinMode( data, OUTPUT );
  pinMode( rck,  OUTPUT );
  pinMode( sck,  OUTPUT );

  pinMode(pin_switch, INPUT);
  digitalWrite(pin_switch, HIGH);
  
  pinMode(pin_buzzer, OUTPUT);
  
  tone(pin_buzzer, 262, 500);
  delay(550);

  tone(pin_buzzer, 262, 500);
  delay(550);
  
  tone(pin_buzzer, 524, 1000);
  
  attachInterrupt(0, on_rising, RISING); 
  
  old_tick = millis();
}

int interval = 1000 * 30;
int is_finished = 0;

void loop() {
//  Serial.println(count);
//  delay(100);

  display_integer(count);

  tick = millis();
  
  if ((tick - old_tick) > interval) {
    if (is_finished == 0) {
      is_finished = 1;
      
      detachInterrupt(0);
      tone(pin_buzzer, 262, 2000);
    }
  }
}

void on_rising() {
  count = count + 1;
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
