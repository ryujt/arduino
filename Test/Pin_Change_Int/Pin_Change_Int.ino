#include <PinChangeInt.h>

#define PIN 5
volatile int burp = 0;

void setup() 
{
  Serial.begin(9600);
  Serial.print("PinChangeInt test on pin ");
  Serial.print(PIN);
  Serial.println();
  
  pinMode(PIN, INPUT);    
  digitalWrite(PIN, HIGH); 

  // attach a PinChange Interrupt to our pin on the rising edge  
  PCintPort::attachInterrupt(PIN, burpcount, RISING); 
// (RISING, FALLING and CHANGE all work with this library)
}

unsigned long old_tick = 0;
unsigned long tick = 0;
unsigned long term = 0;

unsigned long value_sum = 0;
unsigned long value_count = 0;
unsigned long value = 0;

int interval = 1000;

void loop() 
{
  if (old_tick == 0) {
    old_tick = millis();
    return;
  }
  
  tick = millis();
  
  term = term + tick - old_tick;
  
  if (term >= interval) {
    Serial.print("burpcount:\t");
    Serial.println(burp, DEC);
    
    term = 0;
    burp = 0;
  }
  
  old_tick = tick;  
}

void burpcount()
{
  burp++;
}

