class Test
{
  public:
    void test() 
    {
      tone(0, 500);
      delay(500);
    }
};

void setup() {
  pinMode(0, OUTPUT);
}

Test test;

void loop() {
  test.test();
}
