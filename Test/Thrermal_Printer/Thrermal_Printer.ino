#include <SoftwareSerial.h>
#include <Adafruit_Thermal.h>
#include "adalogo.h"
#include "adaqrcode.h"

SoftwareSerial Thermal(5, 6);
Adafruit_Thermal printer(&Thermal);

int heatTime = 80;
int heatInterval = 255;
char printDensity = 15; 
char printBreakTime = 15;

uint8_t pLine[256];

void setup() {
  Thermal.begin(9600);
  printer.begin(); 
  
////  memset(pLine, 0xFF, sizeof(pLine)); 
//  memset(pLine, 0xAA, sizeof(pLine)); 
//  
//  for (int i=0; i<32; i++) 
//  printer.printBitmap(480, 1, (uint8_t *) pLine, false);
//  
//  return;
  
  // Test inverse on & off
  printer.inverseOn();
  printer.println(F("123456789"));
  printer.inverseOff();

  // Test character double-height on & off
  printer.doubleHeightOn();
  printer.println(F("Double Height ON"));
  printer.doubleHeightOff();

  // Set text justification (right, center, left) -- accepts 'L', 'C', 'R'
  printer.justify('R');
  printer.println(F("Right justified"));
  printer.justify('C');
  printer.println(F("Center justified"));
  printer.justify('L');
  printer.println(F("Left justified"));

  // Test more styles
  printer.boldOn();
  printer.println(F("Bold text"));
  printer.boldOff();

  printer.underlineOn();
  printer.println(F("Underlined text"));
  printer.underlineOff();

  printer.setSize('L');        // Set type size, accepts 'S', 'M', 'L'
  printer.println(F("Large"));
  printer.setSize('M');
  printer.println(F("Medium"));
  printer.setSize('S');
  printer.println(F("Small"));

  printer.justify('C');
  printer.println(F("normal\nline\nspacing"));
  printer.setLineHeight(50);
  printer.println(F("Taller\nline\nspacing"));
  printer.setLineHeight(); // Reset to default
  printer.justify('L');

  // Barcode examples:
  // CODE39 is the most common alphanumeric barcode:
  printer.printBarcode("ADAFRUT", CODE39);
  printer.setBarcodeHeight(100);
  // Print UPC line on product barcodes:
  printer.printBarcode("123456789123", UPC_A);

  // Print the 75x75 pixel logo in adalogo.h:
  printer.printBitmap(adalogo_width, adalogo_height, adalogo_data);

  // Print the 135x135 pixel QR code in adaqrcode.h:
  printer.printBitmap(adaqrcode_width, adaqrcode_height, adaqrcode_data);
  printer.println(F("Adafruit!"));
  printer.feed(2);
  
//  printer.sleep();      // Tell printer to sleep
//  delay(3000L);         // Sleep for 3 seconds
//  printer.wake();       // MUST wake() before printing again, even if reset
//  printer.setDefault(); // Restore printer to defaults
}

void initPrinter() {
  //Modify the print speed and heat
  Thermal.write(27);
  Thermal.write(55);
  Thermal.write(7); //Default 64 dots = 8*('7'+1)
  Thermal.write(heatTime); //Default 80 or 800us
  Thermal.write(heatInterval); //Default 2 or 20us
  
  //Modify the print density and timeout
  Thermal.write(18);
  Thermal.write(35);
  
  int printSetting = (printDensity<<4) | printBreakTime;
  Thermal.write(printSetting); //Combination of printDensity and printBreakTime
}

void loop() {
//  Thermal.println(" ... ");
//  Thermal.write(10); //Sends the LF to the printer, advances the paper
//  Thermal.print(" Millis = ");
//  Thermal.println(millis()); 
//  Thermal.write(10);
//  Thermal.write(10); 
//  do { } while (1>0);
}
