#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

String data;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}

void loop()
{
  data="";
  while(Serial.available())
  {
    char c=Serial.read();
    if(c=='#')
    {
      break;
    }
    data+=c;
  }
  if (data.length()>0)
  {
    if (data=="CH1 ON")
    {
      digitalWrite(LED1, HIGH);
      
    }
    if (data=="CH2 ON")
    {
      digitalWrite(LED2, HIGH);
    }
    if (data=="CH3 ON")
    {
      digitalWrite(LED3, HIGH);
    }
    if (data=="CH4 ON")
    {
      digitalWrite(LED4, HIGH);
    }
    if (data=="CH1 OFF")
    {
      digitalWrite(LED1, LOW);
      
    }
    if (data=="CH2 OFF")
    {
      digitalWrite(LED2, LOW);
    }
    if (data=="CH3 OFF")
    {
      digitalWrite(LED3, LOW);
    }
    if (data=="CH4 OFF")
    {
      digitalWrite(LED4, LOW);
    }
  }
  delay(100);
}
