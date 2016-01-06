#include "Nokia5110.h"

void setup()
{ 
  LcdInit();  

  byte line = 0xFF;

  for(int i=0; i<504; i++) {
//    LcdWriteData(line); 
//    line = line << 1;
    LcdWriteData(0b10000000); 
  }

  LcdXY(26, 3);
  LcdWriteString("Hello"); 
}

void loop()
{
}
