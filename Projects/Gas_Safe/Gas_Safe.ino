// LED Digit Display
int pinData = 2; 
int pinClock = 3;
int pinLatch = 4;

// Two Button Module
int pinButtonOn = 5;
int pinButtonOff = 6;

// LED for valve On/Off
int pinValveOn = 7;
int pinValveOff = 8;

int pinBuzzer = 9; 

// Ultra Sonic Sensor
int pinEcho = 10;
int pinTrigger = 11;

// LED for Ultra Sonic Sensor
int pinObjectDetected = 12;

int timer_count_limit = 9 * 1000;

int isObjectDetected = false;
int isValveOpen = false;
int timer_count = 0;

unsigned long oldMillis = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);  
  pinMode(pinLatch, OUTPUT);

  pinMode(pinButtonOn, INPUT);
  pinMode(pinButtonOff, INPUT);
  
  pinMode(pinValveOn, OUTPUT);
  pinMode(pinValveOff, OUTPUT);
  
  pinMode(pinBuzzer, OUTPUT);  
  
  pinMode(pinEcho, INPUT);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinObjectDetected, OUTPUT);
  
  oldMillis = millis();
}

void loop() {
  check_ObjectDetected();
  check_ValveButton();
  check_timer();
  check_value();
}

void check_ObjectDetected()
{
  digitalWrite(pinTrigger, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(pinTrigger, LOW);
  
  long duration = pulseIn(pinEcho, HIGH); 
  
  Serial.print(microsecondsToCentimeters(duration));
  Serial.println();
  
  isObjectDetected = microsecondsToCentimeters(duration) <= 30;
  
  if (isObjectDetected) digitalWrite(pinObjectDetected, HIGH);
  else digitalWrite(pinObjectDetected, LOW);
}

void check_ValveButton()
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
  
  displayNumber(timer_count / 1000);
  
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

void displayNumber(int number)
{
  if (number > 9) number = 9;
  
  byte digits[10] = {
    0b11000000,  // 0
    0b11111001,  // 1
    0b10100100,  // 2
    0b10110000,  // 3
    0b10011001,  // 4
    0b10010010,  // 5
    0b10000010,  // 6
    0b11011000,  // 7
    0b10000000,  // 8
    0b10011000   // 9
  };

  byte data = digits[number];
  
  shiftOut(pinData, pinClock, MSBFIRST, data);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(pinLatch, LOW);
}
