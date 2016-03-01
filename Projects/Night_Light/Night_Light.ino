int pin_LED_LOW = 0;
int pin_LED_HIGH = 1;
int pin_sensor = 3;

void setup() {
  //Serial.begin(9600);

  pinMode(pin_LED_LOW, OUTPUT);
  pinMode(pin_LED_HIGH, OUTPUT);
  pinMode(pin_sensor, INPUT);  

  digitalWrite(pin_LED_LOW, LOW);
}

void loop() {
  int value = analogRead(pin_sensor);
  
  //Serial.println(value);

  if (value > 900) digitalWrite(pin_LED_HIGH, HIGH);
  else digitalWrite(pin_LED_HIGH, LOW);
  
  delay(100);
}
