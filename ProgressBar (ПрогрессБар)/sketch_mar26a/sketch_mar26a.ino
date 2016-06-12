const int DjY = 1;
const int DjX = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(DjX, INPUT);
  pinMode(DjY, INPUT);
}

void loop()
{
  int x = map(analogRead(DjX), 0, 1023, 4, 1);
  int y = map(analogRead(DjY), 0, 1023, 4, 0);
  

  Serial.write(x);
  Serial.write(y);
  delay(100);
}
