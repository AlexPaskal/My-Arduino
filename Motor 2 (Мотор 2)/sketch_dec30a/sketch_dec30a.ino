int mT = 9; 
int t1 = 1; //time. izn.10;
int knp = 12; //button
int knm = 11;
int i = 0;//u


void setup()
{
pinMode(mT, OUTPUT)  ;
pinMode(knp, INPUT);
pinMode(knm, INPUT);
}

void loop()
{
if(digitalRead(knp) == HIGH){
i = i++;
if(i>=255) i = 255;
analogWrite(mT, i);
delay(t1);
}
if(digitalRead(knm) == HIGH){
i = i--;
if(i<=0) i = 0;
analogWrite(mT, i);
delay(t1);
}
///
}
