int pin_1 = 2;
int pin_2 = 3;
int pin_3 = 4;
int pin_4 = 5;

void setup() 
{
}

void loop() 
{
  int v = 0;
  for (int i=1; i < 12; i++) {
    light_up(i); 
    v = v + 15;
    delay(200 - v);
  }

  for (int i=12; i > 1; i--) {
    light_up(i);
    v = v - 15;
    delay(200 - v);
  }
}

void ch_flex(int mode1, int mode2, int mode3, int mode4, int w1, int w2, int w3, int w4)
{
  pinMode(pin_1, mode1);
  pinMode(pin_2, mode2);
  pinMode(pin_3, mode3);
  pinMode(pin_4, mode4);

  digitalWrite(pin_1, w1);
  digitalWrite(pin_2, w2);
  digitalWrite(pin_3, w3);
  digitalWrite(pin_4, w4);
}

void light_up(int no)
{
  switch(no) {
    case 0: ch_flex(INPUT, INPUT, INPUT, INPUT, 0, 0, 0, 0); break;
    case 1: ch_flex(INPUT, OUTPUT, OUTPUT, INPUT, 0, 1, 0, 0); break;
    case 2: ch_flex(INPUT, OUTPUT, OUTPUT, INPUT, 0, 0, 1, 0); break;
    case 3: ch_flex(OUTPUT, INPUT, OUTPUT, INPUT, 1, 0, 0, 0); break;
    case 4: ch_flex(OUTPUT, INPUT, OUTPUT, INPUT, 0, 0, 1, 0); break;
    case 5: ch_flex(INPUT, OUTPUT, INPUT, OUTPUT, 0, 1, 0, 0); break;
    case 6: ch_flex(INPUT, OUTPUT, INPUT, OUTPUT, 0, 0, 0, 1); break;
    case 7: ch_flex(OUTPUT, INPUT, INPUT, OUTPUT, 1, 0, 0, 0); break;
    case 8: ch_flex(OUTPUT, INPUT, INPUT, OUTPUT, 0, 0, 0, 1); break;
    case 9: ch_flex(INPUT, INPUT, OUTPUT, OUTPUT, 0, 0, 0, 1); break;
    case 10: ch_flex(INPUT, INPUT, OUTPUT, OUTPUT, 0, 0, 1, 0); break;
    case 11: ch_flex(OUTPUT, OUTPUT, INPUT, INPUT, 0, 1, 0, 0); break;
    case 12: ch_flex(OUTPUT, OUTPUT, INPUT, INPUT, 1, 0, 0, 0); break;
  }
}
