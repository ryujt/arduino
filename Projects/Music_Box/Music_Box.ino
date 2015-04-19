// 음 높이에 대한 주파수 
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// 음 길이
#define WHOLE 1.0
#define HALF 0.5
#define HALF_DOT 0.75
#define QUARTER 0.25
#define QUARTER_DOT 0.375
#define EIGTH 0.125
#define EIGTH_DOT 0.1875
#define SIXTEENTH 0.0625

// 연주 속도
float duration = 2000;

// My little pony 주제가 음표
const int melody[] PROGMEM = {
  NOTE_FS5, NOTE_A5, NOTE_FS5, NOTE_E5, NOTE_A5,
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_A4,
  NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_E5,
  NOTE_D5, 0, NOTE_CS5, NOTE_D5, NOTE_E5, NOTE_D5,
  /*NOTE_D5*/ NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, 0, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_FS5, NOTE_E5,
  NOTE_D5, 0, NOTE_CS5, NOTE_D5, NOTE_E5, NOTE_D5, 0, NOTE_D5, NOTE_E5,
  NOTE_FS5, 0, NOTE_A5, 0, NOTE_FS5, 0, NOTE_E5, NOTE_D5, NOTE_FS5, NOTE_E5,
  0, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_FS5, NOTE_A5, NOTE_B5, 0, NOTE_A5, NOTE_D5,
  NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_FS5, 0, NOTE_E5, 0,
  NOTE_D5, NOTE_E5, 0, NOTE_FS5, NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_B5, 0, NOTE_A5, NOTE_D5,
  NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, NOTE_A5, 0, NOTE_B5, 0, NOTE_A5, NOTE_A5, 0, NOTE_FS5, NOTE_G5,
  NOTE_D5, 0, NOTE_CS5, NOTE_D5, NOTE_E5, NOTE_D5, 0, NOTE_D5, NOTE_E5,
  NOTE_FS5, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_E5, 0, NOTE_D5, NOTE_FS5, NOTE_E5, NOTE_D5
};

// My little pony 주제가 음 길이
const float noteDurations[] PROGMEM = {
  EIGTH, EIGTH, EIGTH, QUARTER, QUARTER_DOT, 
  EIGTH, EIGTH, EIGTH, QUARTER, QUARTER_DOT, 
  QUARTER, QUARTER, QUARTER, QUARTER,
  EIGTH_DOT, SIXTEENTH, SIXTEENTH, EIGTH, EIGTH_DOT, QUARTER_DOT+ 
  SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, EIGTH, EIGTH, EIGTH, EIGTH_DOT,
  EIGTH_DOT, SIXTEENTH, SIXTEENTH, EIGTH, EIGTH_DOT, EIGTH_DOT, QUARTER, SIXTEENTH, SIXTEENTH,
  EIGTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, EIGTH, SIXTEENTH, EIGTH, QUARTER,
  SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, EIGTH, EIGTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, QUARTER, SIXTEENTH,
  SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, EIGTH, EIGTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, QUARTER, SIXTEENTH,
  SIXTEENTH, SIXTEENTH, SIXTEENTH, EIGTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, EIGTH_DOT, EIGTH,
  SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, EIGTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, SIXTEENTH, EIGTH,
  EIGTH_DOT, SIXTEENTH, SIXTEENTH, EIGTH, EIGTH_DOT, EIGTH, QUARTER, SIXTEENTH, SIXTEENTH,
  EIGTH, SIXTEENTH, EIGTH, EIGTH, EIGTH, SIXTEENTH, EIGTH, EIGTH, EIGTH, SIXTEENTH +
  QUARTER
};

int pinSpeaker = 4;

void setup() 
{
  pinMode(pinSpeaker, OUTPUT);
}

void loop() 
{
  play_music();
}

void play_music()
{
  for (int thisNote = 0; thisNote < 116; thisNote++) {
    // 지금 연주 할 음표의 음 길이를 읽어 옵니다.  (PROGMEM을 사용한 경우에는 배열을 바로 읽어 올 수 없습니다)
    float d = pgm_read_float_near(&noteDurations[thisNote]);

    // 일어 온 음 길이에 연주 속도를 곱해서 사용합니다.  
    // 연주 속도를 바꾸고 싶으면 103번 라인의 duration 값을 변경하면 됩니다.
    int noteDuration = duration * d;
    
    // 지금 연주 할 음표를 구해 옵니다.
    int note = pgm_read_word_near(&melody[thisNote]);

    // 구해 온 음표와 음 길이를 연주합니다.
    tone(pinSpeaker, note, noteDuration);
    
    // 연주가 되는 동안 기다립니다.  
    // 연주 시간보다 조금 더(1.3배) 기다려서 음 간격 확실하게 합니다.  
    // 예를 들어 1박짜리 음표 두 개를 그냥 이어서 연주하면 2박짜리 음표 하나처럼 들리게 됩니다.
    int pauseBetweenNotes = noteDuration * 1.30;    
    delay(pauseBetweenNotes);
   
    // 소리 재생을 멈춥니다.
    noTone(pinSpeaker);
  }
}


