#include <Wire.h>

const int W = 2;
const int R = 3;
const int Y = 4;
const int G = 5;

void setup() {
  // put your setup code here, to run once:
Wire.begin(B0000001);
Wire.onReceive(handler);

pinMode(W, OUTPUT);
pinMode(R, OUTPUT);
pinMode(Y, OUTPUT);
pinMode(G, OUTPUT);

digitalWrite(W, LOW);
digitalWrite(R, LOW);
digitalWrite(Y, LOW);
digitalWrite(G, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
}

  void handler(int LOLint)
{
    byte b = Wire.read();
switch(b)
{
case 'W': AllOff(W); break;
case 'R': AllOff(R); break;
case 'Y': AllOff(Y); break;
case 'G': AllOff(G); break;
}
}

void AllOff(int pin)
{
digitalWrite(W, LOW);
digitalWrite(R, LOW);
digitalWrite(Y, LOW);
digitalWrite(G, LOW);
digitalWrite(pin, HIGH);
}
