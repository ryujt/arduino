#include <Servo.h> 
 
Servo servo2; 
Servo servo3; 
Servo servo4; 

void setup() 
{ 
  servo2.attach(2); 
  servo2.write(30);

  servo3.attach(3); 
  servo3.write(30);

  servo4.attach(4); 
  servo4.write(30); 
} 


void loop() 
{ 
  for (int i=0; i<=30; i++) {
    servo2.write(i); 
    servo3.write(i); 
    servo4.write(i*9); 
    delay(50);
  }
  for (int i=30; i>0; i--) {
    servo2.write(i); 
    servo3.write(i); 
    servo4.write(i*9); 
    delay(50);
  }
} 
