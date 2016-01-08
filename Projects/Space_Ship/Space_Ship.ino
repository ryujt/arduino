#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

bool is_game_end = false;
int pin_left = 11;
int pint_right = 12;
int ship_pos = 43;
int rocks_pos[12];

Adafruit_PCD8544 lcd = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
  Serial.begin(9600);
  
  for (int i=0; i<12; i++) rocks_pos[i] = -99;
  
  srand(analogRead(0));

  pinMode(pin_left, INPUT_PULLUP);
  pinMode(pint_right, INPUT_PULLUP);
  
  lcd.begin();
  lcd.setContrast(50);

  draw();
}

void loop() {
  int r = rand() % 12;

  if (rocks_pos[r] == -99) {
    if ((rand() % 10) == 0) rocks_pos[r] = -8;
  }
  
  if (digitalRead(pin_left) == LOW) ship_pos++;
  if (digitalRead(pint_right) == LOW) ship_pos--; 

  if (ship_pos < 2) ship_pos = 2;
  if (ship_pos > 81) ship_pos = 81;

  for (int i=0; i<12; i++) {
    if (rocks_pos[i] >= 52) rocks_pos[i] = -99;
    if (rocks_pos[i] != -99) rocks_pos[i] ++;

    if (rocks_pos[i] > 44) check_collision(i);
  }

  draw();
}

void check_collision(int no) {
  int r_left = (no * 8) - 4;
  int r_right = (no * 8) + 4;
  int s_left = ship_pos - 2;
  int s_right = ship_pos + 2;

//  if (!is_game_end) {
//  Serial.print("r_left: ");
//  Serial.print(r_left);
//  Serial.print("r_right: ");
//  Serial.print(r_right);
//  Serial.print("s_left: ");
//  Serial.print(s_left);
//  Serial.print("s_right: ");
//  Serial.print(s_right);
//  Serial.println();
//  }

  if ((s_right > r_left) && (s_left < r_right)) is_game_end = true;
}

void draw() {
  lcd.clearDisplay();

  if (is_game_end) return;
  
  for (int i=0; i<12; i++) {
    lcd.fillCircle(i*8, rocks_pos[i], 4, BLACK);
  }

  lcd.fillCircle(ship_pos, 45, 2, BLACK);
  
  lcd.display();
}
