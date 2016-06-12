
const int Photo = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(Photo, INPUT);
}

void loop()
{
  int a = map(analogRead(Photo), 0, 1023, 0, 255);
  Serial.write(a);
  
  delay(100);
}
