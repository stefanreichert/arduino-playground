// BUZZER PIN config
static const int PIN_BUZZER = 3;

// BUZZER config
static const int DURATION_BUZZER_TONE = 10;
static const int FREQUENCY_BUZZER_TONE_NOTIFICATION = 100;
static const int FREQUENCY_BUZZER_TONE_WARNING = 500;
static const int FREQUENCY_BUZZER_TONE_CRITICAL = 1000;

// BUZZER control
void setup_buzzer(){
  pinMode(PIN_BUZZER , OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);
}

void play_notification(){
  tone(PIN_BUZZER, FREQUENCY_BUZZER_TONE_NOTIFICATION, DURATION_BUZZER_TONE);
}

void play_warning(){
  tone(PIN_BUZZER, FREQUENCY_BUZZER_TONE_WARNING, DURATION_BUZZER_TONE);
}

void play_critical(){
  tone(PIN_BUZZER, FREQUENCY_BUZZER_TONE_CRITICAL, DURATION_BUZZER_TONE);
}