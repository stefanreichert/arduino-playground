// BUILT-IN control
static void log(int angle, float distance)
{
  Serial.print("Agle: ");
  Serial.print(angle, 0);
  Serial.print(" °, Distance = ");
  Serial.print(distance, 1);
  Serial.println("%");
}

static void flash_builtin_led()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(10);
  digitalWrite(LED_BUILTIN, LOW);
}

static void setup_built_in(){
  // pin modes
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}