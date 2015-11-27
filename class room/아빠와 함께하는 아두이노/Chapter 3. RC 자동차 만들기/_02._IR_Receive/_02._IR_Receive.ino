#include <IRremote.h>

IRrecv irrecv(7);

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
    irrecv.resume();
  }
}
