#include <musical_notes.h>

void beep (int speakerPin, float noteFrequency, long noteDuration)
{
  tone(speakerPin, noteFrequency);
  delay(noteDuration);
  noTone(speakerPin);
}

const int pinNo = 0;
const int tempo = 500;

void setup() {
	pinMode(pinNo, OUTPUT);
}

void loop() {
       // 1
	beep(pinNo, note_Gb7, 1 * tempo); 
	beep(pinNo, note_A7, 1 * tempo); 
	beep(pinNo, note_Gb7, 1 * tempo); 
	beep(pinNo, note_E7, 2 * tempo); 
	beep(pinNo, note_A7, 3 * tempo); 

       // 2
	beep(pinNo, note_D7, 1 * tempo); 
	beep(pinNo, note_E7, 1 * tempo); 
	beep(pinNo, note_D7, 1 * tempo); 
	beep(pinNo, note_Db7, 2 * tempo); 
	beep(pinNo, note_A6, 3 * tempo); 

	delay(2000);      
}
