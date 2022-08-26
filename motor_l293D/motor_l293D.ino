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
  int value = analogRead(A0);
  Serial.begin(value);
  delay(100);

  //Motor 1
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  analogWrite(11,100);
  
  //Motor 2
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  analogWrite(10,255);
}
