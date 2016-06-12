
void setup()
{
 pinMode(6, OUTPUT); 
}

void loop()
{
for(int i = 0; i<=255; i++)
{
 analogWrite(6, i);
 delay(10); 
}
delay(500);
for(int i = 255; i>=0; i--)
{
 analogWrite(6, i);
 delay(10); 
}
delay(500);
}
