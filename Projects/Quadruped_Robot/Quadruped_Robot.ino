/**
  * Demo: https://youtu.be/IxBvCldOfcI
**/
#include <Servo.h> 

#define servo_count 8
#define delay_interval 100

Servo servos[servo_count];

int start_pos[servo_count] = {
   90,   90,   90,  90,
   40, 150, 155,  40
};

void setup() {
  Serial.begin(9600);
  
  for (int i=0; i<servo_count; i++) {
    servos[i].attach(i+2); 
    servos[i].write(start_pos[i]); 
  }
  
  delay(1000);
}

void loop() {
  go_forward();

//  srand(millis());
//  for (int i=0; i<servo_count; i++) {
//    servos[i].attach(i+2); 
//    servos[i].write(rand() % 180); 
//    
//    delay(100);
//    servos[i].detach(); 
//  }  
}

void set_angle(int no, float angle) {
    servos[no].write(angle); 
}

void push_legs() {
  int positions[4] = {50, 130, 50, 130};
  
  for (int j=1; j<=4; j++) {
    for (int i=0; i<4; i++) {
      if ((i % 2) == 0) {
        servos[i].write(positions[i] + 20 * j);
        Serial.println(positions[i] + 20 * j);
      } else {
        servos[i].write(positions[i] - 20 * j);
        Serial.println(positions[i] - 20 * j);
      }
    }
    
      delay(delay_interval);
  }
}

void right_front_forward() {
  set_angle(5, start_pos[5] - 40);
  set_angle(1, start_pos[1] + 40);
  
  delay(delay_interval);
  
  set_angle(5, start_pos[5]);
}

void right_back_forward() {
  set_angle(7, start_pos[7] + 40);
  set_angle(3, start_pos[3] + 40);
  
  delay(delay_interval);
  
  set_angle(7, start_pos[7]);
}

void left_front_forward() {
  set_angle(4, start_pos[4] + 40);
  set_angle(0, start_pos[0] - 40);
  
  delay(delay_interval);
  
  set_angle(4, start_pos[4]);
}

void left_back_forward() {
  set_angle(6, start_pos[6] - 40);
  set_angle(2, start_pos[2] - 40);
  
  delay(delay_interval);
  
  set_angle(6, start_pos[6]);
}

void go_forward() {
  right_front_forward();
  left_front_forward();
  
  delay(delay_interval);
  
  right_back_forward();
  left_back_forward();

  delay(delay_interval);
  
  push_legs();
}

