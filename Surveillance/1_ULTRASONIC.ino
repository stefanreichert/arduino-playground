// ULTRASONIC PIN config
static int PIN_ULTRASONIC_TRIGGER = 8;
static int PIN_ULTRASONIC_ECHO = 9;


// ULTRASONIC control
void setup_ultrasonic(){
  pinMode(PIN_ULTRASONIC_TRIGGER , OUTPUT);
  pinMode(PIN_ULTRASONIC_ECHO, INPUT);
  digitalWrite(PIN_ULTRASONIC_TRIGGER, LOW);
}

float take_duration_measure(){
  digitalWrite(PIN_ULTRASONIC_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_ULTRASONIC_TRIGGER,HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_ULTRASONIC_TRIGGER,LOW);
  return pulseIn(PIN_ULTRASONIC_ECHO, HIGH);
}

float calculate_distance(){
  float duration = take_duration_measure();
  return (duration * 0.03427) / 2;
}