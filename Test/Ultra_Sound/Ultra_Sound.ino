const int pinIn = 10;
const int pinOut = 11;
const int pinLED = 2;
const int pinBuzzer = 4;

void setup()
{
  pinMode(pinIn, INPUT); 
  pinMode(pinOut, OUTPUT); 
//  pinMode(pinBuzzer, OUTPUT); 
}

void loop()
{
//  tone( pinBuzzer, 400 );
  long duration, cm;

  digitalWrite(pinOut,HIGH); 
  delay(10); 
  digitalWrite(pinOut,LOW);

  duration = pulseIn(pinIn,HIGH); 
  cm = microsecondsToCentimeters(duration); 
  
  digitalWrite(pinLED, LOW); 
  delay(cm);
  digitalWrite(pinLED, HIGH); 
  delay(cm);

  if (cm > 30) {
    digitalWrite(pinLED, LOW); 
  } else {
    digitalWrite(pinLED, HIGH); 
  }
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

 

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
