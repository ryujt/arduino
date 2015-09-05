 /*
 * PIR sensor tester
 */
 
int buzzerPin = 0;
int inputPin = 2; 
int ledPin = 3;   
int swPin = 4;   

int pirState = LOW;
int swOn = false;
 
void setup() {
  pinMode(ledPin, OUTPUT);   
  pinMode(inputPin, INPUT);  
  pinMode(buzzerPin, OUTPUT);
  pinMode(swPin, INPUT);  
}

void loop() {
  if (digitalRead(swPin) == LOW) swOn = true;
  
  if (digitalRead(inputPin) == HIGH) {       
    digitalWrite(ledPin, HIGH);

    if (pirState == LOW) {
      if (swOn) seAlarm(buzzerPin);
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);

    if (pirState == HIGH){
      pirState = LOW;
    }
  }
}

void beep(int speakerPin, float noteFrequency, long noteDuration) {
  int x;
  float microsecondsPerWave = 1000000 / noteFrequency;
  float millisecondsPerCycle = 1000 / (microsecondsPerWave * 2);
  float loopTime = noteDuration * millisecondsPerCycle;
  for (x = 0; x < loopTime; x++) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(microsecondsPerWave);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(microsecondsPerWave);
  }
}

void seAlarm(int pinNo) {
  int i, j;

  for (j = 1; j < 10; j++) {
    for (i = 300; i < 1800; i = i + 40) {
      beep(pinNo, i, 11);
    }
  }
}

