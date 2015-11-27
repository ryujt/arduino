#include "motor.h"

Motor motor(3, 4, 5, 6);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  motor.forward();
  delay(2000);
  
  motor.backward();
  delay(2000);
  
  motor.left();
  delay(2000);
  
  motor.right();
  delay(2000);
}
