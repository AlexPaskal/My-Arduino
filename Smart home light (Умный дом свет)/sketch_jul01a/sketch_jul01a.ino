
void setup()
{
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  attachInterrupt(0, high, RISING);
}

void loop()
{
  unsigned long a = pulseIn(7, HIGH, 20000000);
  if(a == 0) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);
}

void high()
{
 digitalWrite(13, LOW); 
}
