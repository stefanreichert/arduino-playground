// BUILT-IN control
static void log(float temperature, float humidity)
{
  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.print(" °C, Humidity = ");
  Serial.print(humidity, 1);
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