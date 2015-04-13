const int sensorPin= 0;
int smoke_level;

void setup() {
  Serial.begin(9600); 
  pinMode(sensorPin, INPUT);
}

void loop() {
  smoke_level= analogRead(sensorPin);
  Serial.println(smoke_level);
}

