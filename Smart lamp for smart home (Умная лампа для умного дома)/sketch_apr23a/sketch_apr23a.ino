unsigned long a;
int Led = 13;
int Sens = 8;

void setup()
{
  pinMode(Led, OUTPUT);
  pinMode(Sens, INPUT);
  digitalWrite(Led, LOW);
}

void loop()
{
  a = pulseIn(Sens, HIGH, 30000000);
  
  if(a == 0) {digitalWrite(Led, LOW);
  while(digitalRead(Sens) == LOW);
  digitalWrite(Led, HIGH);}
  else digitalWrite(Led, HIGH);
}
