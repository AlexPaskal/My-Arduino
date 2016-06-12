int pR = 3;
int sD = 12;

void setup()
{
  pinMode(sD, OUTPUT);
}

void loop()
{
 int val = analogRead(pR);
if (val<512) {
digitalWrite(sD, HIGH);  
} else{
digitalWrite(sD, LOW);  
}
}
