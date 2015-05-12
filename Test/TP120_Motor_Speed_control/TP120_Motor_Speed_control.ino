const int pin = 5;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  for(int i = 0; i<360; i++) {
    float rad = DEG_TO_RAD * i;
    int sinOut = constrain((sin(rad) * 128) + 128, 0, 255); 
    analogWrite(pin, sinOut);
    delay(15);
  }  
}
