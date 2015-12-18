/**
  * Demo: https://youtu.be/IxBvCldOfcI
**/
#include <Servo.h> 

#define servo_count 8

Servo servos[servo_count];

void setup() {
  for (int i=0; i<servo_count; i++) {
    servos[i].attach(i+2); 
    servos[i].write(90); 
    
    delay(1000);
    servos[i].detach(); 
  }
}

void loop() {
  srand(millis());
  for (int i=0; i<servo_count; i++) {
    servos[i].attach(i+2); 
    servos[i].write(rand() % 180); 
    
    delay(100);
    servos[i].detach(); 
  }  
}
