#include "ir_utils.h"

void setup()
{
  Serial.begin(9600);
  start_ir(7);
}

void loop()
{
  unsigned long result = get_ir_code();
  if (result != 0) {
    Serial.println(result);
  }
}
