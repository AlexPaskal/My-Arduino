const int PotPin = 10;
const int LedPin = 5;

void setup()
{
  pinMode(PotPin, INPUT);
  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin, LOW);
}

void loop()
{
  if(analogRead(PotPin) < 50) digitalWrite(LedPin, LOW);
  else {
  int Chast = map(analogRead(PotPin), 50, 1023, 50, 1000);
  Morganie(Chast);}
}

void Morganie(int Ch)
{
  digitalWrite(LedPin, HIGH);
  delay(50);
  digitalWrite(LedPin, LOW);
  delay(Ch);
}
