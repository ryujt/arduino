#include <SoftwareSerial.h>     

SoftwareSerial cam = SoftwareSerial(2, 3);

byte _reset[]  = {0x56, 0x00, 0x26, 0x00};
byte _stop[]   = {0x56, 0x00, 0x36, 0x01, 0x00};
byte _start[]  = {0x56, 0x00, 0x34, 0x01, 0x00};

void setup() {
  Serial.begin(9600);
  
  cam.begin(38400);
  
  Serial.println("_reset");
  for (int i=0; i<sizeof(_reset); i++) {
    cam.write((byte)_reset[i]);    
  }
  
  while(cam.available()) {
    byte c = cam.read();
    Serial.print(c, HEX);
  }  

  Serial.println("_stop");
  for (int i=0; i<sizeof(_stop); i++) {
    cam.write((byte)_stop[i]);    
  }

  while(cam.available()) {
    byte c = cam.read();
    Serial.print(c, HEX);
  }  

  Serial.println("_start");
  for (int i=0; i<sizeof(_start); i++) {
    cam.write((byte)_start[i]);    
  }

  while(cam.available()) {
    byte c = cam.read();
    Serial.print(c, HEX);
  }  
}

void loop() {
}
