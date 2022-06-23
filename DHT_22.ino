#include "DHT.h"
#define DHTPIN1 8
#define DHTPIN2 9

#define DHTTYPE DHT22

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht1.begin();
  dht2.begin();
}

void loop() {
  float t1 = dht1.readTemperature();
  float t2 = dht2.readTemperature();
  Serial.print(t1);
  Serial.print(" ");
  Serial.println(t2);
  delay(2000);
}
