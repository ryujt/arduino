void setup() 
{
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
}

const unsigned char data[] PROGMEM = {
  8, 53, 243, 51, 38, 191, 173, 196, 220, 82, 78, 43, 217, 28, 211, 38, 
  203, 177, 51, 118, 198, 222, 218, 52, 103, 206, 133, 178, 37, 38, 78, 73, 
  107, 54, 158, 51, 167, 56, 179, 220, 122, 105, 110, 83, 242, 204, 176, 77, 
  40, 41, 227, 20, 51, 110, 141, 89, 98, 30, 166, 189, 18, 154, 158, 201, 
  98, 204, 6, 243, 56, 57, 198, 201, 115, 88, 27, 177, 97, 115, 135, 99, 
  142, 51, 230, 176, 243, 142, 57, 231, 156, 49, 231, 140, 57, 99, 140, 177, 
  99, 204, 28, 35, 198, 204, 57, 115, 238, 156, 57, 103, 206, 157, 115, 231, 
  141, 199, 152, 103, 142, 25, 115, 248, 241, 241, 113, 113, 99, 99, 230, 206, 
  204, 153, 59, 119, 236, 216, 57, 115, 230, 24, 227, 136, 81, 149, 171, 98, 
  172, 66, 54, 206, 220, 49, 99, 204, 41, 99, 145, 36, 167, 61, 188, 227, 
  148, 182, 115, 152, 24, 155, 109, 92, 203, 48, 163, 182, 81, 83, 103, 217, 
  62, 173, 227, 121
};

int getVolume(int index)
{
  unsigned char src = data[index / 8];

  int offset = index % 8;
  unsigned char mask = 1 << offset;
  
  if ((src & mask) == mask) {
    return HIGH;
  } else {
    return LOW;
  }
}

void loop() 
{
  int dataCount = sizeof(data) * 8;
  
  for (int i=0; i<dataCount; i++) {
    digitalWrite(1, getVolume(i));
    delay(1);
  }

  delay(1000);
}
