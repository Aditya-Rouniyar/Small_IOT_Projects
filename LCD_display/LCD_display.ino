#include<LiquidCrystal.h>
#define RS 11
#define EN 10
#define D4 5
#define D5 4
#define D6 3
#define D7 2
 
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print("Aditya is");  
  lcd.setCursor(2,1);
  lcd.print("THE BEST");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(11,0);
  lcd.print("I came, I saw and I conquered");
  for(int i=0; i<=29;i++){
    lcd.scrollDisplayLeft();
    delay(200);
  }
}
