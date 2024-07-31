static int RANGE_AWARE = 200;
static int RANGE_WARNING = 100;
static int RANGE_CRITICAL = 50;

void setup() {
  setup_ultrasonic();
  setup_buzzer();
  setup_servo();
}

void loop() {
  float distance = calculate_distance();
  if(distance <= RANGE_CRITICAL){
    play_critical();
  }
  else if (distance <= RANGE_WARNING){
    play_warning();
  }
  else if (distance <= RANGE_AWARE){
    play_notification();
  }
  turn_servo();
  delay(50);
}
