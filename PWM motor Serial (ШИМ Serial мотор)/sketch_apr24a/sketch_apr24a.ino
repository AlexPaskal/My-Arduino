int Rel1 = 7;
int Rel2 = 8;
int pwm = 3;

void setup()
{
pinMode(Rel1, OUTPUT);
pinMode(Rel2, OUTPUT);
pinMode(pwm, OUTPUT);
  rel(LOW);
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available() == 0);
 byte b = Serial.read();
if(b == 0) rel(LOW);
else{ rel(HIGH);
 analogWrite(pwm, b);}
}

void rel(boolean a)
{
 digitalWrite(Rel1, !a);
 digitalWrite(Rel2, !a); 
}
