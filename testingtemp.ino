#include "Adafruit_DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

float temp;

void setup()
{
    Serial.begin(9600);
    dht.begin();
}

void loop()
{
    temp= dht.readTemperature();
    
    Particle.publish("temp", String(temp), PRIVATE);
    delay(2000);
}