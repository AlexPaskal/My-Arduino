#include <Wire.h>

const int W = 22;
const int R = 23;
const int Y = 24;
const int G = 25;

void setup() {
  // put your setup code here, to run once:
Wire.begin();

pinMode(W, INPUT);
pinMode(R, INPUT);
pinMode(Y, INPUT);
pinMode(G, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(W) == HIGH)
  { Wire.beginTransmission(B0000001);
    Wire.write('W');
    Wire.endTransmission();}
if(digitalRead(R) == HIGH)
  { Wire.beginTransmission(B0000001);
    Wire.write('R');
    Wire.endTransmission();}
if(digitalRead(Y) == HIGH)
  { Wire.beginTransmission(B0000001);
    Wire.write('Y');
    Wire.endTransmission();}
if(digitalRead(G) == HIGH)
  { Wire.beginTransmission(B0000001);
    Wire.write('G');
    Wire.endTransmission();}
}


