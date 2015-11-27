const int AIA = 6;  
const int AIB = 5; 
const int BIA = 4;
const int BIB = 3;

byte speed = 255;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
}

void loop() 
{
  forward();
  delay(2000);
  
  backward();
  delay(2000);
  
  left();
  delay(2000);
  
  right();
  delay(2000);
}

void forward()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}
  
void backward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}
  
void left()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}
  
void right()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}
  

