#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>

#define F_HOST "iot-batch-viii.firebaseio.com"  // Your Firebase Project URL without "http:", "\"  and "/"
#define F_AUTH "2EVIAy39ooyaW7MaviiBNbtVX0CHuslkuYIwDcuf" //Your Firebase Databse secret goes here

#define WIFI_SSID "Panasonic"
#define WIFI_PASSWORD "123456789"

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);// Set the baud rate 115200 in Serial Monitor to display debug messages
  delay(1000);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);   // nodemcu wifi connected to ur hotspot
  Serial.print("connecting tO");
  while (WiFi.status()!=WL_CONNECTED){
  Serial.print(".");
  delay(500);
  }
  Serial.println();
  Serial.println("connected:");
  Serial.println(WIFI_SSID);
  Firebase.begin(F_HOST,F_AUTH);
  dht.begin();   
}

void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  String fireHumid = String(h) + String("%");

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C");
  String fireTemp = String(t) + String(" *C");
  delay(1000);
  
  Firebase.setFloat("Humidity",h);  //Writing the value of the varialble Status from the firebase
  Firebase.setFloat("Temperature",t);  //Writing the value of the varialble Status from the firebase
}
