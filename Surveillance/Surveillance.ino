static int RANGE_AWARE = 400;
static int RANGE_WARNING = 200;
static int RANGE_CRITICAL = 100;

static char SEVERITY_AWARE = 'A';
static char SEVERITY_WARNING = 'W';
static char SEVERITY_CRITICAL = 'C';

void setup() {
  setup_ultrasonic();
  setup_buzzer();
  setup_servo();
  setup_lcd();
  setup_built_in();
}

void loop() {
  int angle = get_angle();
  float distance = calculate_distance();
  if(distance <= RANGE_CRITICAL){
    play_critical();
    update_lcd_text(angle, distance, SEVERITY_CRITICAL);
  }
  else if (distance <= RANGE_WARNING){
    play_warning();
    update_lcd_text(angle, distance, SEVERITY_WARNING);
  }
  else if (distance <= RANGE_AWARE){
    play_notification();
    update_lcd_text(angle, distance, SEVERITY_AWARE);
  }
  else {
    update_lcd_text_no_contact();
  }
  turn_servo();
  flash_builtin_led();
  delay(60);
}
