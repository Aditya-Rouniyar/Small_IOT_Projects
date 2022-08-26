void setup() {
  // put your setup code here, to run once:
  for(int i=8; i<=13; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(7,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(7);
  if(state == 1){
    for(int i=8;i<=13;i++){
      digitalWrite(i,HIGH);
      delay(100);
    }
  }
  else{
    for(int i=8;i<=13;i++){
      digitalWrite(i,LOW);
      delay(100);
    }
  }
}
