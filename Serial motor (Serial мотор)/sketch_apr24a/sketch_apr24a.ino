int a1 = 7;
int a2 = 8;

void setup()
{
pinMode(a1, OUTPUT);
pinMode(a2, OUTPUT);
Serial.begin(9600);
digitalWrite(a1, HIGH);
digitalWrite(a2, HIGH);
}

void loop()
{
 while(Serial.available() == 0)  ;
  char c = Serial.read();
  if(c == '0')
   {digitalWrite(a1, HIGH);
    digitalWrite(a2, HIGH);}
  if(c == '1')
   {digitalWrite(a1, LOW);
    digitalWrite(a2, HIGH);}
  if(c == '2')
   {digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);}
}
