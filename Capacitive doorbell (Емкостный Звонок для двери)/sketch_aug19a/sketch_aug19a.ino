#include <CapacitiveSensor.h>
CapacitiveSensor capSens = CapacitiveSensor(5, 4);

const int R1_1 = 6;
const int R1_2 = 7;

const int R2_1 = 8;
const int R2_2 = 9;

const int T = 7000;

void setup()
{
  pinMode(R1_1, OUTPUT);
  pinMode(R1_2, OUTPUT);
  pinMode(R2_1, OUTPUT);
  pinMode(R2_2, OUTPUT);
}

void loop()
{
  long Value = capSens.capacitiveSensor(30);
  
  if(Value > T)
  {
    if(millis() % 500 < 250)
    {
      digitalWrite(R1_1, HIGH);
      digitalWrite(R1_2, LOW);
      
      digitalWrite(R2_1, HIGH);
      digitalWrite(R2_2, LOW);
    }
    else
    {
      digitalWrite(R1_1, LOW);
      digitalWrite(R1_2, HIGH);
      
      digitalWrite(R2_1, LOW);
      digitalWrite(R2_2, HIGH);      
    }
  }
  
  else
  {
    digitalWrite(R1_1, HIGH);
    digitalWrite(R1_2, HIGH);
    digitalWrite(R2_1, HIGH);
    digitalWrite(R2_2, HIGH);
  }
  
}
