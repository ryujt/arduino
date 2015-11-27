#include <IRremote.h>
#include "motor.h"

IRrecv irrecv(7);
Motor motor(3, 4, 5, 6);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  decode_results results;
  boolean has_result = irrecv.decode(&results);
  if (has_result) {
    Serial.println(results.value);
    
    if (results.value == 16623703) motor.stop();
    if (results.value == 16615543) motor.forward();
    if (results.value == 16619623) motor.backward();
    if (results.value == 16591063) motor.left();
    if (results.value == 16607383) motor.right();
    
    irrecv.resume();
  }
}
