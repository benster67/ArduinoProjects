#include <dht.h>

dht DHT;

#define DHT11_PIN 10


int celcius = 0;
int farenheit = 0;
int humidity = 0;

void setup() {
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  celcius = DHT.temperature;
  farenheit = (celcius * 1.800000) + 32;
  humidity =  DHT.humidity;
  Serial.print("Temperature = ");
  Serial.print(farenheit);
  Serial.println(" Deg");
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println("%");
  delay(1000);
}
