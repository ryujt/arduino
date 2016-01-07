#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <math.h>

#define  PI  3.141592654

Adafruit_PCD8544 lcd = Adafruit_PCD8544(7, 6, 5, 4, 3);

int distances[19];

void setup() {
  memset(&distances[0], 0, sizeof(distances));
  
  srand(analogRead(0));

  lcd.begin();
  lcd.setContrast(50);
  lcd.clearDisplay();
}

void loop() {
  for (int i=0; i<19; i++) {
    int angle = i * 10;
    distances[i] = (rand() % 10) + 31;
    draw_radar();
    delay(250);
  }

  for (int i=(19-1); i>=0; i--) {
    int angle = i * 10;
    distances[i] = (rand() % 10) + 31;
    draw_radar();
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

void draw_radar() {
    lcd.clearDisplay();
    for (int i=1; i<10; i++) lcd.drawCircle(42, 48, i*5, BLACK);
    for (int i=0; i<19; i++) lcd.fillCircle(get_x(i, distances[i]), get_y(i, distances[i]), 2, BLACK);
    lcd.display();
}
