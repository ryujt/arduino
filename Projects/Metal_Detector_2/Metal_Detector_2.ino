#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int pin_led = 13;

const int ring_size = 16;
int index = 0;
double data_ring[ring_size];
double data_sum = 0;

void setup() {
  memset(data_ring, 0, sizeof(data_ring));
  
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);

  lcd.init();                     
  lcd.backlight();
}

unsigned long old_tick = 0;
unsigned long term = 0;
int count = 0;
double sum = 0;

void loop() {
  if (old_tick == 0) {
    old_tick = millis();
    return;
  }
  
  int value = analogRead(A1);

  count++;
  sum = sum + value;
  
  unsigned long tick = millis();
  term = term + tick - old_tick;
  old_tick = tick;
  
  if (term >= 500) {
    double value = sum / count;
    count = 0;
    sum = 0;
    term = 0;
    
    index = (index + 1) % ring_size;
    data_sum = data_sum - data_ring[index] + value;
    data_ring[index] = value;
    
    double avg = data_sum / ring_size;

    lcd.clear();
    lcd.print("value: ");  lcd.print(value);
    lcd.setCursor(0, 1);
    lcd.print("diff: ");  lcd.print(abs(value - avg));   
   
    Serial.print("value: ");  Serial.println(value);
    Serial.print("diff: ");  Serial.println(abs(value - avg));

    if (abs(value - avg) > (avg * 0.01)) {
        digitalWrite(pin_led, HIGH);
    }  else {
        digitalWrite(pin_led, LOW);
    }
  }
}


