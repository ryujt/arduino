uint8_t myLED = 13;
volatile int count = 0;
volatile int state = LOW;
 
void interrupt0() { // when butten2: 0->1, this runs.
    if (state==HIGH) state=LOW;
    else state = HIGH;
    
    count++;
}
 
void setup() {
    Serial.begin(9600);
    pinMode(myLED, OUTPUT);
    attachInterrupt(0, interrupt0, RISING);
}
 
void loop()
{
    digitalWrite(myLED, state);
    Serial.println(count);
}
