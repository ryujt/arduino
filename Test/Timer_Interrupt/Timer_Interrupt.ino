volatile int rpmcount = 0;

void on_falling()
{
  rpmcount++;
}

void setup()
{
  Serial.begin( 9600 );
  
  attachInterrupt(0, on_falling, FALLING);
}

void loop()
{
   delay(1000);

   detachInterrupt(0);
   
   Serial.print(rpmcount);
   rpmcount = 0;

   attachInterrupt(0, on_falling, FALLING);
}
