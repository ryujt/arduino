#include <ESP8266.h>
#include <SoftwareSerial.h>

SoftwareSerial esp8266Serial = SoftwareSerial(2, 3);
ESP8266 wifi = ESP8266(esp8266Serial);

void setup() {
    Serial.begin(9600);

    // ESP8266
    esp8266Serial.begin(9600);
    wifi.begin();
    wifi.setTimeout(1000);

    char version[16] = {};
    wifi.getVersion(version, 16);
    Serial.print("getVersion: ");
    Serial.println(version);

    Serial.print("setWifiMode: ");
    Serial.println(bool2ok(wifi.setMode(ESP8266_WIFI_ACCESSPOINT)));
    
    Serial.print("joinAP: ");
    Serial.println(bool2ok(wifi.joinAP("U+NetC2B3", "pw")));
}

void loop() {
  // put your main code here, to run repeatedly:

}

String bool2ok(bool value) {
  if (value) return "Ok"; else return "No";
}
