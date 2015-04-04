int sensorPin = 0;

void setup() {
  pinMode( sensorPin, INPUT );
  Serial.begin(9600);
}
void loop() {
//  int value = analogRead(sensorPin); 
  int value = digitalRead(sensorPin); 

   Serial.println(value);
   
   delay(100);
}
