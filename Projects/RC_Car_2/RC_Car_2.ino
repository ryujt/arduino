#include <IRremote.h>

#define UP_KEY     0xFD8877
#define DOWN_KEY   0xFD9867
#define LEFT_KEY   0xFD28D7
#define RIGHT_KEY  0xFD6897
#define OK_KEY     0xFDA857
#define STAR_KEY   0xFD30CF
#define SHARP_KEY  0xFD708F

const int AIA = 5;  
const int AIB = 4; 
const int BIA = 3;
const int BIB = 2;

const int pin_ir = 6;

IRrecv irrecv(pin_ir);

decode_results results;

byte speed = 255;

void setup()
{
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results)) {
    switch(results.value) {
      case UP_KEY:     forward();    break;
      case DOWN_KEY:   backward();   break;
      case LEFT_KEY:   left();       break;
      case RIGHT_KEY:  right();      break;
      case OK_KEY:     do_stop();    break;
    }
    
    irrecv.resume();
  }
}

void forward()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}
  
void backward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}
  
void left()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}
  
void right()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

void do_stop()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}
