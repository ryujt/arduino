#include <Servo.h> 
 
int servoPin = 2;

Servo servo; 

int angle = 0; 

void setup() 
{ 
    Serial.begin(9600);
    servo.attach(servoPin); 
    servo.write(angle); 
} 


void loop() 
{ 
  for(angle = 0; angle < 180; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
  for(angle = 180; angle > 0; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
} 
