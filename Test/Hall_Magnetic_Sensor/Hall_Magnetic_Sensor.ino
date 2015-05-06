int LED = 10;
int Sensor = 3;
int val;

void setup()
{
  Serial.begin( 9600 );
  
  pinMode(LED, OUTPUT);
  pinMode(Sensor, INPUT);
}

void loop()
{
  val = digitalRead( Sensor );
  if(val==LOW) {
    digitalWrite(LED,LOW);
  } else {
    digitalWrite(LED,HIGH);
  }
}
