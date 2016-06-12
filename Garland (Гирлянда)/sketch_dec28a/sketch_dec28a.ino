int aI = 0;
int aR = 11;
int aB = 10;
int aG = 9;

void setup()
{
 pinMode(aR, OUTPUT);
 pinMode(aB, OUTPUT);
 pinMode(aG, OUTPUT);
}

void loop()
{
int val = (analogRead(aI));

if (val<=256) {
digitalWrite(aR, HIGH);
digitalWrite(aB, LOW);
digitalWrite(aG, LOW);
}
if (val>256 && val<=512) {
digitalWrite(aR, LOW);
digitalWrite(aB, HIGH);
digitalWrite(aG, LOW);
}
if (val>512 && val<=768) {
digitalWrite(aR, LOW);
digitalWrite(aB, LOW);
digitalWrite(aG, HIGH);
}
else {
digitalWrite(aR, LOW);
digitalWrite(aB, LOW);
digitalWrite(aG, LOW);  
}

}
