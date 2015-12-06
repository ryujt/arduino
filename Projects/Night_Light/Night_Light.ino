int pin_LED = 1;
int pin_sensor = 3;

void setup() {
//  Serial.begin(9600);
  
  pinMode(pin_LED, OUTPUT);
  pinMode(pin_sensor, INPUT);
}

void loop() {
  int value = analogRead(pin_sensor);
  
//  Serial.println(value);

  if (value > 900) digitalWrite(pin_LED, HIGH);
  else digitalWrite(pin_LED, LOW);
  
  delay(100);
}
