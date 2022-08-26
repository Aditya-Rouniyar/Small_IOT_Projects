#include <Adafruit_Sensor.h>
#include<DHT.h>

#define D_PIN 9

#define D_TYPE DHT11

DHT dht(D_PIN,D_TYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  if (isnan(h) || isnan(t)){
    Serial.print("CANNOT READ VALUE FROM SENSOR");
    return;
  }
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("Humidity: ");
  Serial.println(h);
  delay(500);
}
