int sd = 10;
void setup()
{
 // Serial.begin(9600);
  pinMode(sd, OUTPUT);
}

void loop()
{ 

for(int i=0; i<=250; i++)
{
analogWrite(sd, i);
delay(10);
}

//delay(1000);


} 





