#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27,16,2);

DHT dht(3, DHT11); 

int dustPin = 0;
float dustVal = 0;
float dustDensity = 0;
 
int ledPower = 5;
int delayTime = 280;
int delayTime2 = 40;
float offTime = 9680;

void setup()
{
  lcd.init();                     
  lcd.backlight();

  pinMode(ledPower, OUTPUT);
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.print(t);
  lcd.print(", ");
  lcd.print("H=");
  lcd.print(h);
  
  //////////////////////////////////

  digitalWrite(ledPower, HIGH); 
  delayMicroseconds(delayTime);

  dustVal = analogRead(dustPin);
  delayMicroseconds(delayTime2);

  digitalWrite(ledPower, LOW);
  delayMicroseconds(offTime);

  dustDensity = 0.17 * (dustVal * 0.0049) - 0.1;
  if (dustDensity < 0) dustDensity = 0;

  lcd.setCursor(0, 1);
  lcd.print("D=");
  lcd.print(dustDensity);
  lcd.print(" (mg/m3)");

  //////////////////////////////////

  delay(500); 
}

