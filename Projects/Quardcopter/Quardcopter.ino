#include<Wire.h>

const int MPU=0x68;

const int pinM01 = 6;
const int pinM02 = 7;
const int pinM03 = 8;
const int pinM04 = 9;

int baseU = 0;

int baseX = -800;
int baseY = -150;

int m01 = baseU;
int m02 = baseU;
int m03 = baseU;
int m04 = baseU;

int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup()
{
  Serial.begin(9600);

  pinMode(pinM01, OUTPUT);
  pinMode(pinM02, OUTPUT);
  pinMode(pinM03, OUTPUT);
  pinMode(pinM04, OUTPUT);

  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop()
{
  getData();
  
  m01 = baseU;
  m02 = baseU;
  m03 = baseU;
  m04 = baseU;
    
  if (AcX > -800) doLeft();
  else if (AcX < -800) doRight();
  
  if (AcY < -150) doUp();
  else if (AcY > -150) doDown();
  
  if (m01 > 255) m01 = 255;
  if (m02 > 255) m02 = 255;
  if (m03 > 255) m03 = 255;
  if (m04 > 255) m04 = 255;

  analogWrite(pinM01, m01);
  analogWrite(pinM02, m02);
  analogWrite(pinM03, m03);
  analogWrite(pinM04, m04);

  Serial.print("m01 = "); Serial.println(m01);
  Serial.print("m02 = "); Serial.println(m02);
  Serial.print("m03 = "); Serial.println(m03);
  Serial.print("m04 = "); Serial.println(m04);
}

void doLeft()
{
  Serial.println("doLeft");
  
  int u = (AcX + 800) / 10;
  
  m01 = m01 + u;
  m03 = m03 + u;
}

void doRight()
{
  Serial.println("doRight");
  
  int u = (-AcX - 800) / 10;
  
  m02 = baseU + u;
  m04 = baseU + u;
}

void doUp()
{
  Serial.println("doUp");
  
  int u = (-AcY - 150) / 10;
  
  m01 = m01 + u;
  m02 = m02 + u;
}

void doDown()
{
  Serial.println("doDown");
  
  int u = (AcY + 150) / 10;

  m03 = m03 + u;
  m04 = m04 + u;
}

void getData() 
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);

  Wire.requestFrom(MPU, 14, true);  

  AcX = Wire.read() << 8 | Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY = Wire.read() << 8 | Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp = Wire.read() << 8 | Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX = Wire.read() << 8 | Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY = Wire.read() << 8 | Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ = Wire.read() << 8 | Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
}  
