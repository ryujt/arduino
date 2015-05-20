#include <SoftwareSerial.h>

// RX (TX of GPS), TX (RX ofGPS)
SoftwareSerial mySerial(10, 11); 

void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600);

  digitalWrite(11,HIGH);
  
  while(mySerial.available()) {
    char ch = mySerial.read();
    Serial.print(ch);
    if (ch == '\r') break;
  }  
}

void loop()
{
  if (mySerial.available()) {
    char c = mySerial.read();
    Serial.print(c);
  }
}
