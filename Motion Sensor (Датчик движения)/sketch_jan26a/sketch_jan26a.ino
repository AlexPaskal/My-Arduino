int HC_SR = 7;
int LedPin = 13;

void setup()
{
  pinMode(HC_SR, INPUT);
  pinMode(LedPin, OUTPUT);
  
  digitalWrite(LedPin, LOW);
}

void loop()
{
  if(digitalRead(HC_SR) == HIGH)   digitalWrite(LedPin, HIGH);
  else   digitalWrite(LedPin, LOW);
}
