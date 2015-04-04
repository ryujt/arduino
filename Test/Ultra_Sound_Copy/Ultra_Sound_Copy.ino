const int pinOut = 2;
const int pinIn = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(pinOut,OUTPUT); 
  pinMode(pinIn,INPUT); 
}

void loop()
{
  long duration, cm;

  digitalWrite(pinOut,HIGH); 
  delayMicroseconds(10); 
  digitalWrite(pinOut,LOW);

  duration = pulseIn(pinIn,HIGH); 
  cm = microsecondsToCentimeters(duration); 

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(300); 
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
