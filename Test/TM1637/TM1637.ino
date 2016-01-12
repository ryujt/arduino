#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(0x0f);
}

void loop() {
  for (int i=0; i<9999; i++) {
    display.showNumberDec(i, true, 4, 0);
  }
}

