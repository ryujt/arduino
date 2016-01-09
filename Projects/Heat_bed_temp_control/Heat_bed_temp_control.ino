#include <TM1637Display.h>

#define CLK 2
#define DIO 3

int target_temp = 65;

int pin_temp = 0;
int pin_relay = 6;
int pin_led = 13;

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  
  pinMode(pin_relay, OUTPUT);
  pinMode(pin_led, OUTPUT);
  
  display.setBrightness(0x0f);
}

void loop() {
  int tempReading = analogRead(pin_temp);
  float tempVolts = tempReading * 5.0 / 1024.0;
  float tempC = (tempVolts - 0.5) * 100.0;

  Serial.println(tempC);

  display.showNumberDec(tempC, true, 4, 0);

  if (tempC > target_temp) {
    digitalWrite(pin_relay, HIGH);
    digitalWrite(pin_led, HIGH);
  } else {
    digitalWrite(pin_relay, LOW);
    digitalWrite(pin_led, LOW);
  }
  
  delay(200);
}

