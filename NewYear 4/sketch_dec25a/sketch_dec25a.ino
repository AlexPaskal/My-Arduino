/*
13(orange) -- Red -- 3 -- 23
14(yellow) -- Blue -- 5 -- 22
15(green) -- Green -- 6 -- 21
*/

int rS = 3;
int bS = 5;
int gS = 6;

void setup()
{
pinMode(rS, OUTPUT);  
pinMode(bS, OUTPUT);  
pinMode(gS, OUTPUT);  
}

void loop()
{
  
  
  // Red
for(int i=0; i<=255; i++)
{
analogWrite(rS, i);
delay(10);
}
delay(500);

for(int i=255; i>=0; i--)
{
 analogWrite(rS, i);
delay(10); 
}
delay(500);

  //Blue
for(int i=0; i<=255; i++)
{
analogWrite(bS, i);
delay(10);  
}
delay(500);

for(int i=255; i>=0; i--)
{
analogWrite(bS, i);
delay(10);  
}
delay(500);

 //Green
for(int i=0; i<=255; i++)
{
analogWrite(gS, i);
delay(10);  
}
delay(500);

for(int i=255; i>=0; i--)
{
analogWrite(gS, i);
delay(10);  
}
delay(500);

////////////////////////////////////////////////
}
