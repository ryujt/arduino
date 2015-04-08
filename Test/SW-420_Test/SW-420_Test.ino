int pinSW = 2;
int pinLED = 3;

void setup() {
  pinMode(pinSW, INPUT);
  pinMode(pinLED, OUTPUT);
}

int oldState = 0;

void loop() {
  int state = digitalRead(pinSW);
  
  if (state != oldState) {
    oldState = state;

    digitalWrite(pinLED, HIGH);
    delay(1000);
    digitalWrite(pinLED, LOW);
  }
}
