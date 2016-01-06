int pin_led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
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
  
  int value = analogRead(A0);

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
    
    Serial.print("value: ");  Serial.println(value);

    if (value < 500) {
        digitalWrite(pin_led, HIGH);
    }  else {
        digitalWrite(pin_led, LOW);
    }
  }
}


