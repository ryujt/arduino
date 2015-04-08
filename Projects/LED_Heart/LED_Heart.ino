int pinData = 2; 
int pinClock = 3;
int pinLatch = 4;

void setup() {
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);  
  pinMode(pinLatch, OUTPUT);
  
//  Serial.begin(9600);
}

void loop() {
  all_in_out();
  sequnce();
}

void writeShift(byte data)
{
  shiftOut( pinData, pinClock, MSBFIRST, data );
  digitalWrite( pinLatch, HIGH );
  digitalWrite( pinLatch, LOW );
}

/**
* no = A + 1;  A = 10, B = 20 ...
*/
void set_on_led(int no)
{
//  Serial.println(no);
  
  byte data = 0;
  
  switch (no) {
    case 11: data = 0b10000111; break;
    case 12: data = 0b10001011; break;
    case 13: data = 0b10001101; break;
    case 14: data = 0b10001110; break;
    
    case 21: data = 0b01000111; break;
    case 22: data = 0b01001011; break;
    case 23: data = 0b01001101; break;
    case 24: data = 0b01001110; break;

    case 31: data = 0b00100111; break;
    case 32: data = 0b00101011; break;
    case 33: data = 0b00101101; break;
    case 34: data = 0b00101110; break;

    case 41: data = 0b00010111; break;
    case 42: data = 0b00011011; break;
    case 43: data = 0b00011101; break;
    case 44: data = 0b00011110; break;
    
    default: data = 0;
  }
  
  writeShift( data );
}

void all_in_out()
{
  writeShift( 0b11110000 );
  delay( 500 );

  writeShift( 0b00000000 );
  delay( 500 );
}

void real_sequnce()
{
  set_on_led( 11);  delay( 1000 );
  set_on_led( 12);  delay( 1000 );
  set_on_led( 13);  delay( 1000 );
  set_on_led( 14);  delay( 1000 );

  set_on_led( 21);  delay( 1000 );
  set_on_led( 22);  delay( 1000 );
  set_on_led( 23);  delay( 1000 );
  set_on_led( 24);  delay( 1000 );

  set_on_led( 31);  delay( 1000 );
  set_on_led( 32);  delay( 1000 );
  set_on_led( 33);  delay( 1000 );
  set_on_led( 34);  delay( 1000 );

  set_on_led( 41);  delay( 1000 );
  set_on_led( 42);  delay( 1000 );
  set_on_led( 43);  delay( 1000 );
  set_on_led( 44);  delay( 1000 );
}

void sequnce()
{
  set_on_led( 23);  delay( 100 );
  set_on_led( 24);  delay( 100 );
  set_on_led( 14);  delay( 100 );
  set_on_led( 13);  delay( 100 );
  set_on_led( 12);  delay( 100 );
  set_on_led( 11);  delay( 100 );
  set_on_led( 22);  delay( 100 );
  set_on_led( 21);  delay( 100 );
  set_on_led( 32);  delay( 100 );
  set_on_led( 42);  delay( 100 );
  set_on_led( 43);  delay( 100 );
  set_on_led( 44);  delay( 100 );
  set_on_led( 34);  delay( 100 ); 
  set_on_led( 33);  delay( 100 );
}
