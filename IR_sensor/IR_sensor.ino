int value=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0);
  Serial.println("Old Value=");
  Serial.println(value);
  value = map(value,0,1023,0,100);
  Serial.println("New Mapped Value=");
  Serial.println(value);
  delay(1000);
  int LS=digitalRead(2);
  int RS=digitalRead(3);

  if(LS==1 && RS==1){
    FORWARD();
    //Serial.print("Moving FORWARD");
  }

  if(LS==1 && RS==0){
    RIGHT();
    //Serial.print("Moving RIGHT");
  }

  if(LS==0 && RS==1){
    LEFT();
    //Serial.print("Moving LEFT");
  }

  if(LS==0 && RS==0){
    wait();
    //Serial.print("WAITING");
  }
}

void FORWARD(){
  //Motor 1
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  analogWrite(11,value);

  //MOtor 2
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  analogWrite(10,value);
}

void LEFT(){
  //Motor 1
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
    analogWrite(11,value);

  //MOtor 2
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  analogWrite(10,value);

}

void RIGHT(){
  //Motor 1
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  analogWrite(11,value);


  //MOtor 2
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  analogWrite(10,value);

}

void wait(){
  //Motor 1
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  analogWrite(11,0);


  //MOtor 2
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  analogWrite(10,0);

}
