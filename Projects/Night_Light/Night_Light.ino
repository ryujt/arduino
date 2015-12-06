int pin_LED = 1;
int pin_sensor = 2;

void setup() {
  pinMode(pin_LED, OUTPUT);
  pinMode(pin_sensor, INPUT);
}

void loop() {
  int value = analogRead(pin_sensor);

  if (value < 100) digitalWrite(pin_LED, HIGH);
  else digitalWrite(pin_LED, LOW);
  
  delay(100);
}
