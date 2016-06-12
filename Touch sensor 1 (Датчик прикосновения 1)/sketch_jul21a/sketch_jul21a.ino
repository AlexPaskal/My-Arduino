#include <CapacitiveSensor.h>
CapacitiveSensor capSens = CapacitiveSensor(5, 4);
const int thr = 3600;

volatile int counter = 0;

void setup()
{
  attachInterrupt(0, On, RISING);
  attachInterrupt(1, Off, RISING);
  pinMode(13, OUTPUT); //Signal
  pinMode(12, OUTPUT); //On/off
}

volatile boolean a = false;

void loop()
{
  digitalWrite(12, !a);
  if(!a) digitalWrite(13, HIGH);
  while(!a);
  if(millis() % 50 == 0)
  {
  long Value = capSens.capacitiveSensor(30);
  if(Value > thr)
    counter++;
  }
  
   while(counter >= 2)
   {
   if(millis() % 1000 == 0) digitalWrite(13, LOW);
   if(millis() % 1000 == 500) digitalWrite(13, HIGH);
   }
 digitalWrite(13, HIGH);
}

void On()
{
  a = true;
  counter = 0;
}
void Off()
{
  a = false;
  counter = 0;
}
