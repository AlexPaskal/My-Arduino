int gL = 2;
int yL = 7;
int rL = 8;

void setup()
{
pinMode(gL, OUTPUT);
pinMode(yL, OUTPUT);
pinMode(rL, OUTPUT);
}

void loop()
{
digitalWrite(gL, HIGH);
delay(3000);
 digitalWrite(gL, LOW);
 delay(500);
 digitalWrite(gL, HIGH);
 delay(500);
 digitalWrite(gL, LOW);
 delay(500);
 digitalWrite(gL, HIGH);
 delay(500);
 digitalWrite(gL, LOW);

digitalWrite(yL, HIGH);
delay(2000);
digitalWrite(yL, LOW);

digitalWrite(rL, HIGH);
delay(3000);
 digitalWrite(rL, LOW);
 delay(500);
 digitalWrite(rL, HIGH);
 delay(500);
 digitalWrite(rL, LOW);
 delay(500);
 digitalWrite(rL, HIGH);
 delay(500);
 digitalWrite(rL, LOW);

digitalWrite(yL, HIGH);
delay(2000);
digitalWrite(yL, LOW);
}
