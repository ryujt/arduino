#include <avr/pgmspace.h>

int Max7219_pinCLK = 2;
int Max7219_pinCS = 1;
int Max7219_pinDIN = 0;

void Write_Max7219_byte(unsigned char DATA) {
	digitalWrite(Max7219_pinCS, LOW);
	for (int i = 8; i >= 1; i--) {
		digitalWrite(Max7219_pinCLK, LOW);
		digitalWrite(Max7219_pinDIN, DATA&0x80);
		DATA = DATA << 1;
		digitalWrite(Max7219_pinCLK, HIGH);
	}
}

void Write_Max7219(unsigned char address, unsigned char dat) {
	digitalWrite(Max7219_pinCS, LOW);
	Write_Max7219_byte(address);
	Write_Max7219_byte(dat);
	digitalWrite(Max7219_pinCS, HIGH);
}

void Init_MAX7219(void) {
	Write_Max7219(0x09, 0x00);
	Write_Max7219(0x0a, 0x03);
	Write_Max7219(0x0b, 0x07);
	Write_Max7219(0x0c, 0x01);
	Write_Max7219(0x0f, 0x00);
}

const int lines = 6;

const unsigned char disp1[lines][8] PROGMEM = {
      { 0x72, 0x8A, 0x8A, 0x73, 0x02, 0x42, 0x40, 0x7E },
      { 0x81, 0x87, 0x81, 0xF7, 0x01, 0x39, 0x44, 0x38 },
      { 0x32, 0x02, 0x7A, 0x03, 0x32, 0x4A, 0x4A, 0x32 },
      { 0x25, 0x25, 0x25, 0x2D, 0x65, 0x95, 0x95, 0x95 },
      { 0x3C, 0x42, 0x42, 0x3C, 0x00, 0x24, 0x24, 0xFF },
      { 0x3C, 0x42, 0x42, 0x02, 0x0C, 0x10, 0x00, 0x10 }
};

void setup() {
	pinMode(Max7219_pinCLK, OUTPUT);
	pinMode(Max7219_pinCS, OUTPUT);
	pinMode(Max7219_pinDIN, OUTPUT);
	delay(500);
	Init_MAX7219();
}

void loop() {
	for (int j = 0; j < lines; j++) {
		for (int i = 1; i < 9; i++)
			Write_Max7219(i, pgm_read_byte(&disp1[j][i - 1]));
		delay(500);
	}
}
