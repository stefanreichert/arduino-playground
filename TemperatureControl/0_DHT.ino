#include <dht_nonblocking.h>

// DHT pin config
static const int PIN_DHT_SENSOR = 9;

// DHT config
DHT_nonblocking dht_sensor(PIN_DHT_SENSOR, DHT_TYPE_11);

// DHT control
static bool measure(float *temperature, float *humidity){
  return dht_sensor.measure(temperature, humidity);
}