#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int tempPin = 0;
int pin_relay = 2;
int pin_led = 13;
int pin_up = 8;
int pin_down = 7;

int target_temp = 65;

LiquidCrystal_I2C lcd(0x27,16,2);
 
void setup() 
{
//  Serial.begin(9600);

  lcd.init();                     
  lcd.backlight();
  
  pinMode(pin_relay, OUTPUT);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_up, INPUT);
  pinMode(pin_down, INPUT);
}
 
void loop()
{
  int tempReading = analogRead(tempPin);
  float tempVolts = tempReading * 5.0 / 1024.0;
  float tempC = (tempVolts - 0.5) * 100.0;
  float tempF = tempC * 9.0 / 5.0 + 32.0;

  if (digitalRead(pin_up) == LOW) {
    target_temp++;
  }
  
  if (digitalRead(pin_down) == LOW) {
    target_temp--;
  }
  
//  Serial.print("Target temp: ");
//  Serial.println(target_temp);
//  Serial.print("Temp: ");
//  Serial.println(tempC);

  lcd.clear();
  lcd.print("Target temp: ");
  lcd.print(target_temp);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempC);
  
  if (tempC > target_temp) {
    digitalWrite(pin_relay, HIGH);
    digitalWrite(pin_led, LOW);
  } else {
    digitalWrite(pin_relay, LOW);
    digitalWrite(pin_led, HIGH);
  }
  
 delay(200);
}

