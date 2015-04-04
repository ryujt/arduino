void setup() {
  pinMode( 0, INPUT );
  pinMode( 8, OUTPUT );
}

int isOn = 0;

void loop() {
  if (digitalRead(0) == HIGH) {
    if (isOn) {
      isOn = 0;
      digitalWrite( 8, LOW );
    } else {
      isOn = 1;
      digitalWrite( 8, HIGH );
    }
  }
  
  delay(100);
}
