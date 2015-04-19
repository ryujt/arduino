int pinData = 2; 
int pinClock = 3;
int pinLatch = 4;

int pinButton = 1;

int leftNo = 0;
int rightNo = 0;

void setup() {
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);  
  pinMode(pinLatch, OUTPUT);
  
  pinMode(pinButton, INPUT);
}

void loop() {
  if (digitalRead(pinButton) == LOW) {
    srand(millis());
    leftNo = (rand() % 6) + 1;
    rightNo = (rand() % 6) + 1;
  }
  
  left(leftNo);
  right(rightNo);
}

void writeShift(byte data)
{
  shiftOut( pinData, pinClock, MSBFIRST, data );
  digitalWrite( pinLatch, HIGH );
  digitalWrite( pinLatch, LOW );
}

void left(int no)
{
   switch (no) {
     case 1: 
       writeShift( 0b00010111 ); 
       break;
     
     case 2: 
       writeShift( 0b00011110 );
       writeShift( 0b00101011 );
       break;
       
     case 3:
       writeShift( 0b00011110 ); 
       writeShift( 0b00010111 ); 
       writeShift( 0b00101011 );  
       break;
       
     case 4: 
       writeShift( 0b00011110 ); 
       writeShift( 0b00101110 ); 
       writeShift( 0b00011011 ); 
       writeShift( 0b00101011 );  
       break;
       
     case 5:
       writeShift( 0b00011110 ); 
       writeShift( 0b00101110 ); 
       writeShift( 0b00011011 ); 
       writeShift( 0b00101011 );
       writeShift( 0b00010111 );    
       break;
       
     case 6: 
       writeShift( 0b00011110 ); 
       writeShift( 0b00011101 ); 
       writeShift( 0b00101110 ); 
       writeShift( 0b00011011 ); 
       writeShift( 0b00101101 ); 
       writeShift( 0b00101011 );
       break;
       
       default: writeShift(0);
   } 
}

void right(int no)
{
   switch (no) {
     case 1: 
       writeShift( 0b01000111 ); 
       break;
     
     case 2: 
       writeShift( 0b01001110 );
       writeShift( 0b10001011 );
       break;
       
     case 3:
       writeShift( 0b01001110 );
       writeShift( 0b01000111 ); 
       writeShift( 0b10001011 );
       break;
       
     case 4: 
       writeShift( 0b01001110 ); 
       writeShift( 0b10001110 ); 
       writeShift( 0b01001011 ); 
       writeShift( 0b10001011 );  
       break;
       
     case 5:
       writeShift( 0b01001110 ); 
       writeShift( 0b10001110 ); 
       writeShift( 0b01001011 ); 
       writeShift( 0b10001011 );
       writeShift( 0b01000111 );    
       break;
       
     case 6: 
       writeShift( 0b01001110 ); 
       writeShift( 0b01001101 ); 
       writeShift( 0b10001110 ); 
       writeShift( 0b01001011 ); 
       writeShift( 0b10001101 ); 
       writeShift( 0b10001011 );
       break;
       
       default: writeShift(0);
   } 
}

