void setup() {
  // put your setup code here, to run once:
  for(int i=8; i<=13; i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=8;i<=13;i++){
    digitalWrite(i,HIGH);
    delay(100);
  }
  for(int i=8;i<=13;i++){
    digitalWrite(i,LOW);
    delay(100);
  }
}
