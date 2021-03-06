#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <math.h>
#include <Servo.h> 

#define  PI  3.141592654

Adafruit_PCD8544 lcd = Adafruit_PCD8544(7, 6, 5, 4, 3);

Servo servo; 

int pin_echo = 9;
int pin_trig = 10;

int distances[19];

void setup() {
  Serial.begin(9600);
  
//  memset(&distances[0], 0, sizeof(distances));
  for (int i=0; i<19; i++) distances[i] = 0;
  
  lcd.begin();
  lcd.setContrast(50);
  lcd.clearDisplay();

  servo.attach(8); 

  pinMode(pin_echo, INPUT); 
  pinMode(pin_trig, OUTPUT); 
}

void loop() {
  for (int i=0; i<19; i++) {    
    draw_radar(i);
    delay(250);
  }

  for (int i=(19-1); i>=0; i--) {
    draw_radar(i);
    delay(250);
  }
}

int get_x(int no, int d) {
  if ((no >= 0) & (no <=18)) return cos((180-no * 10) * PI / 180) * d + 42;
  else return -100;
}

int get_y(int no, int d) {
  if ((no >= 0) & (no <=18)) return 48 - sin(no * 10 * PI / 180) * d;
  else return -100;
}

void draw_radar(int no) {
  int angle = no * 10;
  
  servo.write(angle);
  
  digitalWrite(pin_trig, HIGH); 
  delay(10); 
  digitalWrite(pin_trig, LOW);

  long duration = pulseIn(pin_echo, HIGH); 
  long cm = duration / 29 / 2; 

  Serial.println(cm);

  distances[no] = cm ;

  lcd.clearDisplay();
  for (int i=1; i<10; i++) lcd.drawCircle(42, 48, i*5, BLACK);
  for (int i=0; i<19; i++) lcd.fillCircle(get_x(i, distances[i]), get_y(i, distances[i]), 2, BLACK);
  lcd.display();
}
