int pinData = 2; 
int pinClock = 3;
int pinLatch = 4;

void setup() {
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);  
  pinMode(pinLatch, OUTPUT);
}

byte data;

void loop() {
  data = 0b11110000;
  shiftOut(pinData, pinClock, MSBFIRST, data);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(pinLatch, LOW);
  delay(500);

  data = 0b00000000;
  shiftOut(pinData, pinClock, MSBFIRST, data);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(pinLatch, LOW);
  delay(500);
}
