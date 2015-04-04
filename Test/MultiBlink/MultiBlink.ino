void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

int power_states[] = {LOW, LOW, LOW, LOW, LOW};

void loop() {
  int r = rand();
  int i = r % 5;
  
  if (power_states[i] == LOW) {
    digitalWrite(i, HIGH);    
    power_states[i] = HIGH;
  } else {
    digitalWrite(i, LOW);    
    power_states[i] = LOW;
  }
  
  delay(50);  
}
