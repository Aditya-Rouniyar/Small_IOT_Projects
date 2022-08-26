void setup() {
  // put your setup code here, to run once:
  for(int i=10; i<=13; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(7,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(7);
  if(state == 1) {
    digitalWrite(12,HIGH);
    delay(100);
    digitalWrite(12,LOW);
    delay(100);
    
    for(int i=11;i<=13;i=i+2){
      digitalWrite(i,HIGH);
      delay(80);
      digitalWrite(i,LOW);
      delay(80);
    }
  }
  else{
    for(int i=11;i<=13;i++){
      digitalWrite(i,LOW);
      delay(80);
    }
  }
}
