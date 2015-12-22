#include &lt;IRremote.h>

#define AIA 5
#define AIB 6
#define BIA 3
#define BIB 4
    
IRrecv irrecv(7);

void setup() {
  irrecv.enableIRIn();

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  
  do_stop();  
}

void loop() {
  decode_results results;
  boolean has_result = irrecv.decode(&results);
  if (has_result) {
    if (results.value == 16623703) do_stop();
    if (results.value == 16615543) forward();
    if (results.value == 16619623) backward();
    if (results.value == 16591063) left();
    if (results.value == 16607383) right();
    irrecv.resume();
  }
}

void forward() {
  digitalWrite(AIA, HIGH);
  digitalWrite(AIB, LOW);
  digitalWrite(BIA, HIGH);
  digitalWrite(BIB, LOW);
}

void backward() {
  digitalWrite(AIA, LOW);
  digitalWrite(AIB, HIGH);
  digitalWrite(BIA, LOW);
  digitalWrite(BIB, HIGH);
}

void left() {
  digitalWrite(AIA, HIGH);
  digitalWrite(AIB, LOW);
  digitalWrite(BIA, LOW);
  digitalWrite(BIB, HIGH);
}

void right() {
  digitalWrite(AIA, LOW);
  digitalWrite(AIB, HIGH);
  digitalWrite(BIA, HIGH);
  digitalWrite(BIB, LOW);
}

void do_stop() {
  digitalWrite(AIA, LOW);
  digitalWrite(AIB, LOW);
  digitalWrite(BIA, LOW);
  digitalWrite(BIB, LOW);
}
