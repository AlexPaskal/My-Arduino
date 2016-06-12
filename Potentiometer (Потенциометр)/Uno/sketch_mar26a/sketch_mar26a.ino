#include <Servo.h>
Servo servo;

void setup()
{
  Serial.begin(9600);
  servo.attach(10);
}

void loop()
{
  byte Pos = Serial.read();
  Serial.flush();
  int pos = constrain((int)Pos, 0, 170);
  servo.write(pos);
  delay(10);
}
