int pinLED = 1;
int pinSensor = 2;

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinSensor, INPUT);
}

void loop() {
  int value = analogRead(pinSensor);

//  digitalWrite(pinLED, HIGH);

  if (value < 100) digitalWrite(pinLED, HIGH);
  else digitalWrite(pinLED, LOW);
  
  delay(100);
}
