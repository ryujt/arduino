#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <EtherCard.h>

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(3, DHT11); 

int isEthernetOk = 1;

int dustPin = 0;
 
int ledPower = 5;
int delayTime = 280;
int delayTime2 = 40;
float offTime = 9680;

static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
byte Ethernet::buffer[512];

static void my_callback (byte status, word off, word len) {
  Serial.println("http received:");
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

void setup()
{
  Serial.begin(57600);
  Serial.println("setup begin!");

  lcd.init();                     
  lcd.backlight();
  lcd.print("setup begin!");

  pinMode(ledPower, OUTPUT);

  lcd.clear();
  lcd.print("Ethernet start");
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) {
    isEthernetOk = 0;
    Serial.println("Failed to access Ethernet controller");
  }

  lcd.clear();
  lcd.print("DHCP start");
  if ((isEthernetOk) && (!ether.dhcpSetup())) {
    isEthernetOk = 0;
    Serial.println("DHCP failed");
  }

  if (isEthernetOk) {
    ether.printIp("IP:  ", ether.myip);
    ether.printIp("GW:  ", ether.gwip);  
    ether.printIp("DNS: ", ether.dnsip);  
  
    ether.parseIp(ether.hisip, "182.252.178.43");
    ether.printIp("SRV: ", ether.hisip);
  }
}

void loop()
{
  Serial.println("loop start!");

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.print(t);
  lcd.print(", ");
  lcd.print("H=");
  lcd.print(h);
  
  //////////////////////////////////

  digitalWrite(ledPower, HIGH); 
  delayMicroseconds(delayTime);

  float dustVal = analogRead(dustPin);
  delayMicroseconds(delayTime2);

  digitalWrite(ledPower, LOW);
  delayMicroseconds(offTime);

  float d = 0.17 * (dustVal * 0.0049) - 0.1;
  if (d < 0) d = 0;

  lcd.setCursor(0, 1);
  lcd.print("D=");
  lcd.print(d);
  lcd.print(" (mg/m3)");

  //////////////////////////////////

  if (isEthernetOk) {
    Serial.println("http send");
    
    char pMsg[64]; 
    sprintf("?t=%f&h=%f&d=%f", pMsg, t, h, d);
    ether.browseUrl(PSTR("/weather/set_data"), pMsg, "www.helloworld.or.kr", my_callback);
    ether.packetLoop(ether.packetReceive());
  }
  
  delay(1000); 
}

