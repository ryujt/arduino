void setup() 
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

const int datas[] PROGMEM= {
  HIGH, LOW , LOW , LOW , LOW ,
  LOW , HIGH, LOW , LOW , LOW ,
  LOW , HIGH, HIGH, LOW , LOW ,
  LOW , HIGH, LOW , HIGH, LOW ,
  LOW , HIGH, LOW , LOW , HIGH,
  LOW , HIGH, LOW , HIGH, LOW ,
  LOW , HIGH, HIGH, LOW , LOW ,
  LOW , HIGH, LOW , LOW , LOW ,
  HIGH, LOW , LOW , LOW , LOW 
};

int index = 0;

void loop() 
{
  for (int i=0; i<5; i++) {
    digitalWrite( i, datas[i + (index * 5)] );    
//    digitalWrite( i, LOW );    
  }
  
  if (index >= 9) index = 0;

//  digitalWrite( index, HIGH );    
  
  index++;
  
  delay(100);  
}
