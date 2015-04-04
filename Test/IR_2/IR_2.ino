#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define UP_KEY 0xFD8877
#define DOWN_KEY 0xFD9867
#define LEFT_KEY 0xFD28D7
#define RIGHT_KEY 0xFD6897
#define OK_KEY 0xFDA857
#define STAR_KEY 0xFD30CF
#define SHARP_KEY 0xFD708F

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    {
      if (results.value == UP_KEY) {
        Serial.println("UP_KEY");
      } else if (results.value == DOWN_KEY) {
        Serial.println("DOWN_KEY");
      } else if (results.value == LEFT_KEY) {
        Serial.println("LEFT_KEY");
      } else if (results.value == RIGHT_KEY) {
        Serial.println("RIGHT_KEY");
      } else if (results.value == OK_KEY) {
        Serial.println("OK_KEY");
      } else if (results.value == STAR_KEY) {
        Serial.println("STAR_KEY");
      } else if (results.value == SHARP_KEY) {
        Serial.println("SHARP_KEY");
      }      
       
      irrecv.resume();
    }
}
