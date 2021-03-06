#include <IRremote.h>

#define MOTORCLK 4
#define MOTORENABLE 7
#define MOTORDATA 8
#define MOTORLATCH 12

#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR3_A 5
#define MOTOR3_B 7
#define MOTOR4_A 0
#define MOTOR4_B 6

// Arduino pins for the PWM signals.
#define MOTOR1_PWM 11
#define MOTOR2_PWM 3
#define MOTOR3_PWM 6
#define MOTOR4_PWM 5
#define SERVO1_PWM 10
#define SERVO2_PWM 9

// Codes for the motor function.
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

//
#define UP_KEY 0xFD8877
#define DOWN_KEY 0xFD9867
#define LEFT_KEY 0xFD28D7
#define RIGHT_KEY 0xFD6897
#define OK_KEY 0xFDA857
#define STAR_KEY 0xFD30CF
#define SHARP_KEY 0xFD708F

int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn(); 
}

void loop() {
  if (irrecv.decode(&results)) {
      if (results.value == UP_KEY) {
        motor_output(MOTOR1_A, HIGH, 255);
        motor_output(MOTOR1_B, LOW, -1);
        motor_output(MOTOR4_A, HIGH, 255);
        motor_output(MOTOR4_B, LOW, -1);
      } else if (results.value == DOWN_KEY) {
        motor_output(MOTOR1_A, LOW, -1);
        motor_output(MOTOR1_B, HIGH, 255);
        motor_output(MOTOR4_A, LOW, -1);
        motor_output(MOTOR4_B, HIGH, 255);
      } else if (results.value == LEFT_KEY) {
        motor_output(MOTOR1_A, HIGH, 255);
        motor_output(MOTOR1_B, LOW, -1);
        motor_output(MOTOR4_A, LOW, -1);
        motor_output(MOTOR4_B, LOW, -1);
      } else if (results.value == RIGHT_KEY) {
        motor_output(MOTOR1_A, LOW, -1);
        motor_output(MOTOR1_B, LOW, -1);
        motor_output(MOTOR4_A, HIGH, 255);
        motor_output(MOTOR4_B, LOW, -1);
      } else if (results.value == OK_KEY) {
        motor_output(MOTOR1_A, LOW, -1);
        motor_output(MOTOR1_B, LOW, -1);
        motor_output(MOTOR4_A, LOW, -1);
        motor_output(MOTOR4_B, LOW, -1);
      } else if (results.value == STAR_KEY) {
        motor_output(MOTOR1_A, HIGH, 255);
        motor_output(MOTOR1_B, LOW, -1);
        motor_output(MOTOR4_A, LOW, -1);
        motor_output(MOTOR4_B, HIGH, 255);
      } else if (results.value == SHARP_KEY) {
        motor_output(MOTOR1_A, LOW, -1);
        motor_output(MOTOR1_B, HIGH, 255);
        motor_output(MOTOR4_A, HIGH, 255);
        motor_output(MOTOR4_B, LOW, -1);
      } 
      
      irrecv.resume();
  }
}

void motor_output(int output, int high_low, int speed)
{
  int motorPWM;

  switch (output)
  {
  case MOTOR1_A:
  case MOTOR1_B:
    motorPWM = MOTOR1_PWM;
    break;
  case MOTOR2_A:
  case MOTOR2_B:
    motorPWM = MOTOR2_PWM;
    break;
  case MOTOR3_A:
  case MOTOR3_B:
    motorPWM = MOTOR3_PWM;
    break;
  case MOTOR4_A:
  case MOTOR4_B:
    motorPWM = MOTOR4_PWM;
    break;
  default:
    // Use speed as error flag, -3333 = invalid output.
    speed = -3333;
    break;
  }

  if (speed != -3333)
  {
    // Set the direction with the shift register 
    // on the MotorShield, even if the speed = -1.
    // In that case the direction will be set, but
    // not the PWM.
    shiftWrite(output, high_low);

    // set PWM only if it is valid
    if (speed >= 0 && speed <= 255)    
    {
      analogWrite(motorPWM, speed);
    }
  }
}

void shiftWrite(int output, int high_low)
{
  static int latch_copy;
  static int shift_register_initialized = false;

  // Do the initialization on the fly, 
  // at the first time it is used.
  if (!shift_register_initialized)
  {
    // Set pins for shift register to output
    pinMode(MOTORLATCH, OUTPUT);
    pinMode(MOTORENABLE, OUTPUT);
    pinMode(MOTORDATA, OUTPUT);
    pinMode(MOTORCLK, OUTPUT);

    // Set pins for shift register to default value (low);
    digitalWrite(MOTORDATA, LOW);
    digitalWrite(MOTORLATCH, LOW);
    digitalWrite(MOTORCLK, LOW);
    // Enable the shift register, set Enable pin Low.
    digitalWrite(MOTORENABLE, LOW);

    // start with all outputs (of the shift register) low
    latch_copy = 0;

    shift_register_initialized = true;
  }

  // The defines HIGH and LOW are 1 and 0.
  // So this is valid.
  bitWrite(latch_copy, output, high_low);

  // Use the default Arduino 'shiftOut()' function to
  // shift the bits with the MOTORCLK as clock pulse.
  // The 74HC595 shiftregister wants the MSB first.
  // After that, generate a latch pulse with MOTORLATCH.
  shiftOut(MOTORDATA, MOTORCLK, MSBFIRST, latch_copy);
  delayMicroseconds(5);    // For safety, not really needed.
  digitalWrite(MOTORLATCH, HIGH);
  delayMicroseconds(5);    // For safety, not really needed.
  digitalWrite(MOTORLATCH, LOW);
}
