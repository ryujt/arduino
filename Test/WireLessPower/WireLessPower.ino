int pinOut = 4;
int pinIn = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(pinOut, OUTPUT);
//  pinMode(pinIn, INPUT);
}

void loop() 
{
  for (int i=0; i<0xFFFF; i++) {
    digitalWrite(pinOut, HIGH);
    digitalWrite(pinOut, LOW);
  }

//  int sensorValue = analogRead(A0);
//  Serial.println(sensorValue);
  
//  delay(100);
}
