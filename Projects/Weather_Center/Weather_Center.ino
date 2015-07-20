#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <EtherCard.h>

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(3, DHT11); 

static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
byte Ethernet::buffer[512];

int isEthernetOk = 0;

int sendInterval = 50;
int sendCount = 0;

int pinDustSensor = 0;
int pinDustSensorLED = 5;
int pinEthernetSwitch = 7;

void setup()
{
  Serial.begin(57600);
  Serial.println("setup begin!");

  pinMode(pinDustSensorLED, OUTPUT);
  pinMode(pinEthernetSwitch, INPUT_PULLUP);

  lcd.init();                     
  lcd.backlight();
  lcd.print("setup begin!");

  isEthernetOk = (digitalRead(pinEthernetSwitch) == LOW);

  if (isEthernetOk) prepareEthernet();
}

void prepareEthernet()
{
  lcd.clear();
  lcd.print("Ethernet start");
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) {
    isEthernetOk = 0;
    Serial.println("Failed to access Ethernet controller");
  }

  if (isEthernetOk) {
    lcd.clear();
    lcd.print("DHCP start");
    if (!ether.dhcpSetup()) {
      isEthernetOk = 0;
      Serial.println("DHCP failed");
    }
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
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.print(t);
  lcd.print(", ");
  lcd.print("H=");
  lcd.print(h);
  
  //////////////////////////////////

  int delayTime = 280;
  int delayTime2 = 40;
  float offTime = 9680;

  digitalWrite(pinDustSensorLED, HIGH); 
  delayMicroseconds(delayTime);

  float dustVal = analogRead(pinDustSensor);
  delayMicroseconds(delayTime2);

  digitalWrite(pinDustSensorLED, LOW);
  delayMicroseconds(offTime);

  float d = (0.17 * (dustVal * 0.0049) - 0.1) * 1000;
  if (d < 0) d = 0;

  lcd.setCursor(0, 1);
  lcd.print("D=");
  lcd.print(dustVal);
  lcd.print(" (ug/m3)      ");

  //////////////////////////////////

  if (isEthernetOk) {
    sendCount = sendCount + 1;
    if (sendCount >= sendInterval) {
      sendCount = 0;
      
      Serial.println("http send");
      
      char pMsg[64]; 
      sprintf("?t=%f&h=%f&d=%f", pMsg, t, h, d);
      ether.browseUrl(PSTR("/weather/set_data"), pMsg, "www.helloworld.or.kr", my_callback);
      ether.packetLoop(ether.packetReceive());
    }
  }
  
  delay(100); 
}

static void my_callback (byte status, word off, word len) {
  Serial.println("http received:");
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

