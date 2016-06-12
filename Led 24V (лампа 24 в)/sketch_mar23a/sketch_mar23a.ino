
const int led = 6;

void setup()
{
pinMode(led, OUTPUT);
}

void loop()
{
narast();
delay(1000);
spad();
delay(1000); 
}
 
void narast()
{ 
for(int i = 0; i<=1023; i++)
{
  analogWrite(led, i);
  delay(20);
}
}
void spad()
{
  for(int j = 1023; j>=0; j--)
{
  analogWrite(led, j);
  delay(20);
}
}

