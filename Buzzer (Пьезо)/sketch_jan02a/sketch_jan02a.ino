#define buz 6

void setup()
{
  pinMode(buz, OUTPUT);
}

void loop()
{
  tone(buz, 500, 1000);
  delay(500);
  noTone(buz); delay(500);
}
