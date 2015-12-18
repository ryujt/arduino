/**
  * Demo: https://youtu.be/IxBvCldOfcI
**/
#include <Servo.h> 

#define servo_count 8

Servo servos[servo_count];

int start_pos[servo_count] = {
   90,   90,   90,  90,
   40, 140, 155,  40
};

void setup() {
  for (int i=0; i<servo_count; i++) {
    servos[i].attach(i+2); 
    servos[i].write(start_pos[i]); 
    
    delay(500);
    servos[i].detach(); 
  }
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
    servos[no].attach(no+2); 
    servos[no].write(angle); 
    delay(100);
    servos[no].detach(); 
}

void set_start_position() {
  for (int i=0; i<4; i++) {
    servos[i].attach(i+2); 
    servos[i].write(start_pos[i]); 
  }
}

void right_front_start() {
  set_angle(5, start_pos[5]);
  set_angle(1, start_pos[1]);
}

void right_back_start() {
  set_angle(7, start_pos[7]);
  set_angle(3, start_pos[3]);
}

void right_front_forward() {
  set_angle(5, start_pos[5] - 40);
  set_angle(1, start_pos[1] + 40);
  set_angle(5, start_pos[5]);
}

void right_back_forward() {
  set_angle(7, start_pos[7] + 40);
  set_angle(3, start_pos[3] + 40);
  set_angle(7, start_pos[7]);
}

void left_front_start() {
  set_angle(4, start_pos[4]);
  set_angle(0, start_pos[0]);
}

void left_back_start() {
  set_angle(6, start_pos[6]);
  set_angle(2, start_pos[2]);
}

void left_front_forward() {
  set_angle(4, start_pos[4] + 40);
  set_angle(0, start_pos[0] - 40);
  set_angle(4, start_pos[4]);
}

void left_back_forward() {
  set_angle(6, start_pos[6] - 40);
  set_angle(2, start_pos[2] - 40);
  set_angle(6, start_pos[6]);
}

void go_forward() {
  right_front_forward();
  left_front_forward();
  
  right_back_forward();
  left_back_forward();

  right_front_start();
  left_front_start();

  right_back_start();
  left_back_start();
}

