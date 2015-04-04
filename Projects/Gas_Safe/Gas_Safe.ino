int pinEcho = 2;
int pinTrigger = 3;
int pinObjectDetected = 4;
int pinButtonOn = 5;
int pinButtonOff = 6;
int pinValveOn = 7;
int pinValveOff = 8;
int pinBuzzer = 9;

int timer_count_limit = 9 * 1000;

int isObjectDetected = false;
int isValveOpen = false;
int timer_count = 0;

unsigned long oldMillis = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pinEcho, OUTPUT);
  pinMode(pinTrigger, INPUT);
  pinMode(pinObjectDetected, OUTPUT);
  pinMode(pinButtonOn, INPUT);
  pinMode(pinButtonOff, INPUT);
  pinMode(pinValveOn, OUTPUT);
  pinMode(pinValveOff, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);  
  
  oldMillis = millis();
}

void loop() {
  check_ObjectDetected();
  check_ValueButton();
  check_timer();
  check_value();
}

void check_ObjectDetected()
{
  digitalWrite(pinEcho, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(pinEcho, LOW);
  
  long duration = pulseIn(pinTrigger, HIGH); 
  
  isObjectDetected = microsecondsToCentimeters(duration) <= 30;
  
  if (isObjectDetected) digitalWrite(pinObjectDetected, HIGH);
  else digitalWrite(pinObjectDetected, LOW);
}

void check_ValueButton()
{
  if (digitalRead(pinButtonOn)  == LOW) isValveOpen = true;
  if (digitalRead(pinButtonOff) == LOW) isValveOpen = false;

  if (isValveOpen) {
    digitalWrite(pinValveOn, HIGH);
    digitalWrite(pinValveOff, LOW);
  } else {
    digitalWrite(pinValveOn, LOW);
    digitalWrite(pinValveOff, HIGH);
  }  
}

void check_timer()
{
  unsigned long currentMillis = millis();
  
  if (isObjectDetected || (!isValveOpen)) {
    timer_count = 0;
  } else {  
    timer_count = timer_count + (currentMillis - oldMillis);
  }
  
  Serial.print(timer_count / 1000);
  Serial.println();  
  
  oldMillis = currentMillis;
}

void check_value()
{
  if ((isValveOpen) && (timer_count >= timer_count_limit)) {
    isValveOpen = false;

    digitalWrite(pinValveOn, LOW);
    digitalWrite(pinValveOff, HIGH);

    alarm(pinBuzzer);
  }
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void beep(int speakerPin, float noteFrequency, long noteDuration) {
	int x;
	// Convert the frequency to microseconds
	float microsecondsPerWave = 1000000 / noteFrequency;
	// Calculate how many milliseconds there are per HIGH/LOW cycles.
	float millisecondsPerCycle = 1000 / (microsecondsPerWave * 2);
	// Multiply noteDuration * number or cycles per millisecond
	float loopTime = noteDuration * millisecondsPerCycle;
	// Play the note for the calculated loopTime.
	for (x = 0; x < loopTime; x++) {
		digitalWrite(speakerPin, HIGH);
		delayMicroseconds(microsecondsPerWave);
		digitalWrite(speakerPin, LOW);
		delayMicroseconds(microsecondsPerWave);
	}
}

void alarm(int pinNo) {
  int i, j;

	for (j = 1; j < 10; j++) {
		for (i = 300; i < 1800; i = i + 40) {
			beep(pinNo, i, 11);
		}
	}
}
