// BUZZER PIN config
static const int PIN_BUZZER = 8;

// BUZZER config
static const int DURATION_BUZZER_TONE = 200;
static const int FREQUENCY_BUZZER_TONE = 500;

// BUZZER control
void setup_buzzer(){
  pinMode(PIN_BUZZER , OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);
}

void play_notification(){
  tone(PIN_BUZZER, FREQUENCY_BUZZER_TONE, DURATION_BUZZER_TONE);
}

void play_warning(){
  play_notification();
  delay(100);
  play_notification();
}

void play_critical(){
  play_warning();
  delay(100);
  play_warning();
}