#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define F_HOST "iot-batch-viii.firebaseio.com"  // Your Firebase Project URL without "http:", "\"  and "/"
#define F_AUTH "2EVIAy39ooyaW7MaviiBNbtVX0CHuslkuYIwDcuf" //Your Firebase Databse secret goes here

#define WIFI_SSID "Panasonic"
#define WIFI_PASSWORD "123456789"

//This is used for the Arduino
#define LED1 14 //D5
#define LED2 12 //D6
#define LED3 13 //D7
#define LED4 15 //D8

//This is the variable which stores from database
int val1, val2, val3, val4;

void setup() 
{
  Serial.begin(115200);// Set the baud rate 115200 in Serial Monitor to display debug messages
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);   // nodemcu wifi connected to ur hotspot
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("connected:");

  Firebase.begin(F_HOST,F_AUTH);   
}

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(F_HOST, F_AUTH); // initialize the firebase with HOST name anf AUTH key
}

void loop() 
{
  if (Firebase.failed())
      {
      Serial.print("NETWORK ERROR");
      Serial.println(Firebase.error());
      firebasereconnect();
      return;
      }
  
  val1=Firebase.getString("4_CHANNEL/CH1").toInt();  //Reading the value of the varialble Status from the firebase
  val2=Firebase.getString("4_CHANNEL/CH2").toInt();  //Reading the value of the varialble Status from the firebase
  val3=Firebase.getString("4_CHANNEL/CH3").toInt();  //Reading the value of the varialble Status from the firebase
  val4=Firebase.getString("4_CHANNEL/CH4").toInt();  //Reading the value of the varialble Status from the firebase
  
  if(val1==1)                        // If, the Status is 1, turn on the LED1
     {
      digitalWrite(LED1,HIGH);
      Serial.println("LED 1 ON");
    }
 if(val1==0)                         // If, the Status is 0, turn Off the LED1
    {                                      
      digitalWrite(LED1,LOW);
      Serial.println("LED 1 OFF");
    }
if(val2==1)                          // If, the Status is 1, turn on the LED2
     {
      digitalWrite(LED2,HIGH);
      Serial.println("LED 2 ON");
    }
 if(val2==0)                         // If, the Status is 0, turn Off the LED2
    {                                      
      digitalWrite(LED2,LOW);
      Serial.println("LED 2 OFF");
    }
if(val3==1)                          // If, the Status is 1, turn on the LED3
     {
      digitalWrite(LED3,HIGH);
      Serial.println("LED 3 ON");
    }
if(val3==0)                          // If, the Status is 0, turn Off the LED3
    {                                      
      digitalWrite(LED3,LOW);
      Serial.println("LED 3 OFF");
    }
 if(val4==1)                         // If, the Status is 1, turn on the LED4
     {
      digitalWrite(LED4,HIGH);
      Serial.println("LED 4 ON");
    }
if(val4==0)                          // If, the Status is 0, turn Off the LED4
    {                                      
      digitalWrite(LED4,LOW);
      Serial.println("LED 4 OFF");
    }    
}
