unsigned long old_tick = 0;
unsigned long tick;
unsigned long term = 0;

int count = 0;
double sum = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (old_tick == 0) {
    old_tick = millis();
    return;
  }
  
  int value = analogRead(A5);

  count++;
  sum = sum + value;
  
  tick = millis();
  
  term = term + tick - old_tick;
  
  old_tick = tick;
  
  if (term >= 1000) {
    Serial.println(sum / count  );
    
    count = 0;
    sum = 0;
    term = 0;
  }
}
