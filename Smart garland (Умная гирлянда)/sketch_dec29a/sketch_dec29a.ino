int aI = 0;
int aR = 11;
int aB = 10; //yellow
int aG = 9; //Blue

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
delay(500);
digitalWrite(aR, LOW);
digitalWrite(aB, HIGH);
digitalWrite(aG, LOW);
delay(500);
digitalWrite(aR, LOW);
digitalWrite(aB, LOW);
digitalWrite(aG, HIGH);
delay(500);
}
if (val>256 && val<=512) {
digitalWrite(aR, HIGH);
digitalWrite(aB, LOW);
digitalWrite(aG, LOW);
delay(500);
digitalWrite(aR, LOW);
digitalWrite(aB, HIGH);
digitalWrite(aG, LOW);
delay(500);
digitalWrite(aR, LOW);
digitalWrite(aB, LOW);
digitalWrite(aG, HIGH);
delay(500);
digitalWrite(aR, LOW);
digitalWrite(aB, HIGH);
digitalWrite(aG, LOW);
delay(500);
}
if (val>512 && val<=768) {
//digitalWrite(aR, HIGH);
//delay(250);
digitalWrite(aB, HIGH);
delay(250);
digitalWrite(aG, HIGH);
delay(250);
digitalWrite(aR, LOW);
delay(250);
digitalWrite(aB, LOW);
delay(250);
digitalWrite(aB, HIGH);
delay(250);
digitalWrite(aR, HIGH);
delay(250);
digitalWrite(aG, LOW);
delay(250);
digitalWrite(aB, LOW);//
delay(250);
}
else {
digitalWrite(aR, LOW);
digitalWrite(aB, LOW);
digitalWrite(aG, LOW);  
}
  
}
