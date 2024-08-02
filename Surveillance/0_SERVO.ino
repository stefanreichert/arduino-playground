#include<Servo.h>

// SERVO PIN config
static int PIN_SERVO = 2;

// SERVO config
Servo servo;

static int CENTER_SERVO = 90;
static int ANGLE_SERVO = 180;
static int DIRECTION_SERVO_RIGHT = 1;
static int DIRECTION_SERVO_LEFT = -1;

int servo_angle = CENTER_SERVO;
int outer_left_angle = CENTER_SERVO - (ANGLE_SERVO - CENTER_SERVO);
int outer_right_angle = CENTER_SERVO + (ANGLE_SERVO - CENTER_SERVO);
int direction = DIRECTION_SERVO_RIGHT;

// SERVO control
void setup_servo(){
  servo.attach(PIN_SERVO);
  servo.write(servo_angle);    
  delay(50);
}

int get_angle(){
  return servo_angle;
}

void turn_servo(){
  if(direction == DIRECTION_SERVO_RIGHT && servo_angle >= outer_right_angle){
      direction = DIRECTION_SERVO_LEFT;
  }
  else if(direction == DIRECTION_SERVO_LEFT && servo_angle <= outer_left_angle){
      direction = DIRECTION_SERVO_RIGHT;
  }
  servo_angle = servo_angle + (direction * 2);
  servo.write(servo_angle);
  delay(15);
}

