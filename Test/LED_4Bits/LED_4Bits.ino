// Sample code for http://www.banggood.com/4-Bits-Digital-Tube-LED-Display-Module-Board-For-Arduino-p-931236.html

unsigned char LED_BCD[16] =
  { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e }; 

int data = 2;  
int rck  = 3;
int sck  = 4;

void setup() {               
  pinMode( data, OUTPUT );
  pinMode( rck,  OUTPUT );
  pinMode( sck,  OUTPUT );
}

void loop() {
  for(byte i=0; i<4; ++i) display_number(i, i, 0);
}

void display_integer(int value)
{
  int p = 1000;
  
  for (int i=3; i>=0; i--) {
    int d = value / p;
    p = p / 10;
    display_number( i, d, 0 );
    value = value - d * 1000;
  }
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
