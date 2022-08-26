#include<LiquidCrystal.h>
#define RS 7
#define EN 6
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define trig 10
#define echo 9
 
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,distance;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = 0.034*duration/2;
  lcd.clear();
  lcd.print("Distance = ");
  lcd.print(distance);
  lcd.print("cm");
  delay(100);
}
