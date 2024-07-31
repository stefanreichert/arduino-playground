static void update(float temperature, float humidity){
  log(temperature, humidity);
  update_lcd_text(temperature, humidity);
  update_led_mode(calculate_led_mode(temperature));
}

void setup() {
  setup_lcd();
  setup_led();
  setup_built_in();
}

void loop() {
  float temperature;
  float humidity;
  
  flash_builtin_led();
  if(measure(&temperature, &humidity) == true){
    update(temperature, humidity);
  }
  delay(4000);
}
