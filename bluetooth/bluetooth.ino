#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char data = 0;
  if (Serial.available())
  {
    data = Serial.read();
    if (data == '1')
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, HIGH);
    }
    if (data == '0')
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
    }
  }
}
