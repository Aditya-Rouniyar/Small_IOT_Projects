#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define D_PIN 1
#define D_TYPE DHT11

BlynkTimer Timer;

DHT dht(D_PIN,D_TYPE);
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "hu3dciSlaE7jDspu0t2tKTAAPZZHlIuc";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ady";
char pass[] = "123456789";

void SendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
   Serial.print("Failed To Read Sensor Value");
   return; 
  }
  Blynk.virtualWrite(V5,t);
  Blynk.virtualWrite(V6,t);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  Timer.setInterval(1000L,SendSensor);
}

void loop()
{
  Timer.run();
  Blynk.run();
}
