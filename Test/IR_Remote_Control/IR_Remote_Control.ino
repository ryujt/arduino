#include <IRremote.h>

#define UP_KEY     0xFD8877
#define DOWN_KEY   0xFD9867
#define LEFT_KEY   0xFD28D7
#define RIGHT_KEY  0xFD6897
#define OK_KEY     0xFDA857
#define STAR_KEY   0xFD30CF
#define SHARP_KEY  0xFD708F

const int pin_ir = 7;

IRrecv irrecv(pin_ir);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results)) {
    Serial.print(results.value);
    Serial.print(": ");
    
    switch(results.value) {
      case UP_KEY:     Serial.println("UP_KEY");     break;
      case DOWN_KEY:   Serial.println("DOWN_KEY");   break;
      case LEFT_KEY:   Serial.println("LEFT_KEY");   break;
      case RIGHT_KEY:  Serial.println("RIGHT_KEY");  break;
      case OK_KEY:     Serial.println("OK_KEY");     break;
      case STAR_KEY:   Serial.println("STAR_KEY");   break;
      case SHARP_KEY:  Serial.println("UP_KEY");     break;
      default: Serial.println();
    }
    
    irrecv.resume();
  }
}
