int datapin = 2; 
int clockpin = 3;
int latchpin = 4;

void setup()
{
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
}

void loop()
{
  for (int i=0; i<10; i++) {
    displayNumber(i);
    delay(1000);
  }
}

void displayNumber(int number)
{
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
  
  shiftOut(datapin, clockpin, MSBFIRST, data);
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 0  
//  shiftWrite(0, LOW);
//  shiftWrite(1, LOW);
//  shiftWrite(2, LOW);
//  shiftWrite(3, LOW);
//  shiftWrite(4, LOW);
//  shiftWrite(5, LOW);
//  delay(1000);
//  
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 1
//  shiftWrite(1, LOW);
//  shiftWrite(2, LOW);
//  delay(1000);
//
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 2
//  shiftWrite(0, LOW);
//  shiftWrite(1, LOW);
//  shiftWrite(3, LOW);
//  shiftWrite(4, LOW);
//  shiftWrite(6, LOW);
//  delay(1000);
//
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 3  
//  shiftWrite(0, LOW);
//  shiftWrite(1, LOW);
//  shiftWrite(2, LOW);
//  shiftWrite(3, LOW);
//  shiftWrite(6, LOW);
//  delay(1000);
//
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 4  
//  shiftWrite(1, LOW);
//  shiftWrite(2, LOW);
//  shiftWrite(5, LOW);
//  shiftWrite(6, LOW);
//  delay(1000);
//
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 5  
//  shiftWrite(0, LOW);
//  shiftWrite(2, LOW);
//  shiftWrite(3, LOW);
//  shiftWrite(5, LOW);
//  shiftWrite(6, LOW);
//  delay(1000);
//
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 6  
//  shiftWrite(0, LOW);
//  shiftWrite(2, LOW);
//  shiftWrite(3, LOW);
//  shiftWrite(4, LOW);
//  shiftWrite(5, LOW);
//  shiftWrite(6, LOW);
//  delay(1000);
//
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 7  
//  shiftWrite(0, LOW);
//  shiftWrite(1, LOW);
//  shiftWrite(2, LOW);
//  shiftWrite(5, LOW);
//  delay(1000);
//
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 8  
//  shiftWrite(0, LOW);
//  shiftWrite(1, LOW);
//  shiftWrite(2, LOW);
//  shiftWrite(3, LOW);
//  shiftWrite(4, LOW);
//  shiftWrite(5, LOW);
//  shiftWrite(6, LOW);
//  delay(1000);
//
//  for (int i=0; i<8; i++) shiftWrite(i, HIGH);
//  // 9  
//  shiftWrite(0, LOW);
//  shiftWrite(1, LOW);
//  shiftWrite(2, LOW);
//  shiftWrite(5, LOW);
//  shiftWrite(6, LOW);
//  delay(1000);

