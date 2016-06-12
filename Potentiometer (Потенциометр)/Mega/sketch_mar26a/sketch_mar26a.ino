const int PotPin = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(PotPin, INPUT);
}

void loop()
{
  byte res = analogRead(PotPin);
  byte Res = map(res, 0, 1023, 0, 170);
  Serial.flush();
  Serial.write(Res);
  delay(10);
}
