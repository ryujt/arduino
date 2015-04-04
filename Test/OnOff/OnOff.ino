const int button1Pin = 2;  
const int button2Pin = 3;  
const int ledOn =  12;    
const int ledOff =  13;   

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  pinMode(ledOn, OUTPUT);      
  pinMode(ledOff, OUTPUT);   

  Serial.begin(9600);  
}

int isOn = 0;

void loop()
{
  if (isOn) {
    digitalWrite(ledOn, HIGH);
    digitalWrite(ledOff, LOW);
  } else {
    digitalWrite(ledOn, LOW);
    digitalWrite(ledOff, HIGH);
  }
  
  if (digitalRead(button1Pin) == LOW) {
    isOn = 1; 
    Serial.println("button1Pin");
  }
  if (digitalRead(button2Pin) == LOW) {
    isOn = 0; 
    Serial.println("button2Pin");
  }
}

