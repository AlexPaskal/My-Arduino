//int LedPin = 13;

void setup()
{
Serial.begin(9600);
//pinMode(LedPin, OUTPUT);
}

void loop()
{
  while(Serial.available() == 0);
  char a = Serial.read();
  Serial.write(a+'1');
  Serial.flush();
}
