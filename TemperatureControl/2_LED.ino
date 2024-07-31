// temperature threshold constants
static const float TEMP_THRESHOLD_COLD = 18.00;
static const float TEMP_THRESHOLD_HOT = 24.00;

// LED pin config
static const int PIN_LED_RED = 6;
static const int PIN_LED_GREEN = 7;
static const int PIN_LED_BLUE = 8;

// LED config
static const int INDEX_RED = 0;
static const int INDEX_GREEN = 1;
static const int INDEX_BLUE = 2;
static const int MODE_HOT[] = {HIGH, LOW, LOW};
static const int MODE_FINE[] = {LOW, HIGH, LOW};
static const int MODE_COLD[] = {LOW, LOW, HIGH};
static const int MODE_UNKNOWN[] = {LOW, LOW, LOW};

// LED control
static void update_led_mode(int mode[])
{
  digitalWrite(PIN_LED_RED, mode[INDEX_RED]);
  digitalWrite(PIN_LED_GREEN, mode[INDEX_GREEN]);
  digitalWrite(PIN_LED_BLUE, mode[INDEX_BLUE]);
}

static int calculate_led_mode(float temperature){
  if (temperature <= TEMP_THRESHOLD_COLD){
    return MODE_COLD; 
  }
  else if (temperature >= TEMP_THRESHOLD_HOT){
    return MODE_HOT;
  }
  else{
    return MODE_FINE;
  }
}

static void setup_led(){
  // pin modes
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);

  // turn off LEDs
  update_led_mode(MODE_UNKNOWN);
}