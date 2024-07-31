#include<Servo.h>

// SERVO PIN config
static int PIN_SERVO = 8;

// SERVO config
Servo servo;

static int CENTER_SERVO = 90;
static int ANGLE_SERVO = 140;
static int DIRECTION_SERVO_RIGHT = 1;
static int DIRECTION_SERVO_LEFT = -1;

int servo_position = CENTER_SERVO;
int outer_left_position = CENTER_SERVO - (ANGLE_SERVO - CENTER_SERVO);
int outer_right_position = CENTER_SERVO + (ANGLE_SERVO - CENTER_SERVO);
int direction = DIRECTION_SERVO_RIGHT;

// SERVO control
void setup_servo(){
    servo.write(servo_position);    
    delay(50);
}

void turn_servo(){
  if(direction == DIRECTION_SERVO_RIGHT && servo_position == outer_right_position){
      direction = DIRECTION_SERVO_LEFT;
  }
  else if(direction == DIRECTION_SERVO_LEFT && servo_position == outer_left_position){
      direction = DIRECTION_SERVO_RIGHT;
  }
  servo_position = servo_position + direction;
  servo.write(servo_position);
}

