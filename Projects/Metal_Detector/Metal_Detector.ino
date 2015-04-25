#include <PinChangeInt.h>

#define pin_led   3
#define pin_pulse 5

volatile int pulse_count = 0;

void setup() 
{
  Serial.begin( 9600 );
  
  pinMode( pin_led, OUTPUT);    

  pinMode( pin_pulse, INPUT );    
  digitalWrite( pin_pulse, HIGH ); 

  PCintPort::attachInterrupt( pin_pulse, on_pulse, RISING ); 
}

unsigned long old_tick = 0;
unsigned long tick = 0;
unsigned long term = 0;

int value = 0;

int interval = 100;

void loop() 
{
  if (old_tick == 0) {
    old_tick = millis();
    return;
  }
  
  tick = millis();
  
  term = term + tick - old_tick;
  
  if (term >= interval) {
    value = pulse_count;
    pulse_count = 0;

    value = value * term / interval;

    term = 0;

    // TODO: 
    if (abs(value - 150) > 100) {
      digitalWrite( pin_led, HIGH );
    } else {
      digitalWrite( pin_led, LOW );
    }
    
    Serial.print( "pulse_count:\t" );
    Serial.println( value, DEC) ;    
  }
  
  old_tick = tick;  
}

void on_pulse()
{
  pulse_count++;
}

