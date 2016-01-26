#include <TM1637Display.h>

#define CLK 3
#define DIO 2

int target_temp = 65;

int pin_temp = 0;
int pin_relay = 4;
int pin_sw_01 = 8;
int pin_sw_02 = 9;
int pin_led = 13;

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  
  pinMode(pin_sw_01, INPUT_PULLUP);
  pinMode(pin_sw_02, INPUT_PULLUP);

  pinMode(pin_relay, OUTPUT);
  pinMode(pin_led, OUTPUT);
  
  display.setBrightness(0x08);
//  display.setBrightness(0x0f);
}

void loop() {
  if (digitalRead(pin_sw_01) == LOW) {
    target_temp = 80;
    display.showNumberDec(target_temp, true, 4, 0);
    return;
  }
  
  if (digitalRead(pin_sw_02) == LOW) {
    target_temp = 65; 
    display.showNumberDec(target_temp, true, 4, 0);
    return;
  }
  
  int tempReading = analogRead(pin_temp);
  float tempVolts = tempReading * 5.0 / 1024.0;
  float tempC = (tempVolts - 0.5) * 100.0;

  Serial.print("target_temp: ");
  Serial.print(target_temp);
  Serial.print(", tempC: ");
  Serial.println(tempC);

  display.showNumberDec(tempC, true, 4, 0);

  if (tempC < target_temp) {
    digitalWrite(pin_relay, HIGH);
    digitalWrite(pin_led, HIGH);
  } else {
    digitalWrite(pin_relay, LOW);
    digitalWrite(pin_led, LOW);
  }
  
  delay(200);
}

