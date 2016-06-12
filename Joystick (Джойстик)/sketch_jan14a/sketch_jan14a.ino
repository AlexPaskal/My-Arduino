
void setup()
{
Serial.begin(9600);
pinMode(2, INPUT);
  
}

void loop()
{
int x = analogRead(0);
int y = analogRead(1);
boolean b = digitalRead(2);
Serial.print("x=");
Serial.print(x);
Serial.print("; y=");
Serial.print(y);
Serial.print("; button ");
if(b == HIGH) Serial.println("ON ."); else Serial.println("OFF .");

delay(500);

  
}
