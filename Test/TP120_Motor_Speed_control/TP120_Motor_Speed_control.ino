const int pin = 5;

void setup() {
  pinMode( pin, OUTPUT );
}

void loop() {
  for (int i = 0; i<=255; i++) {
    analogWrite( pin, i );
    delay( 10 );
  }  
}
