int sO = 3; //OUTPUT
int a = 0;
//int b = 0;
#include <Servo.h>
Servo myS;

void setup()
{
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  
  myS.attach(3);
}

void loop()
{
if (digitalRead(7) == HIGH){
a++;
if(a>=90) a = 90;
myS.write(a);
delay(10);
}  
  
if (digitalRead(8) == HIGH){
a--;
if(a<=0) a = 0;
myS.write(a);
delay(10);
}  
}
