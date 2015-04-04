int sound = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sound = digitalRead(2);
  if (sound == 1) {	                   // If loud sound
    Serial.println("Sound detected!");
    delay(100);				   // Wait 1/10 second
  }				           //   Repeat
}


