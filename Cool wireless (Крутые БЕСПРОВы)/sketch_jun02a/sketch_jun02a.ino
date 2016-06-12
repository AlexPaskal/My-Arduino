#include <Servo.h>
#include <IR.h>

const int r1 = 22;
const int r2 = 24;
const int r3 = 26;
const int y4 = 28;
const int y5 = 30;
const int y6 = 32;
const int g7 = 34;
const int g8 = 36;
const int g9 = 38;

const int b1 = 23;
const int b2 = 25;
const int b3 = 27;

const int light = 7;

int a = 0;
int l = 255;
boolean li = false;
int Step = 90;

Servo servo;
IR ir;

void setup()
{
  servo.attach(10);
  servo.write(90);
  ir.pinIR(9);
  ir.readEEPROM();
  
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(y4, OUTPUT);
  pinMode(y5, OUTPUT);
  pinMode(y6, OUTPUT);
  pinMode(g7, OUTPUT);
  pinMode(g8, OUTPUT);
  pinMode(g9, OUTPUT);
  
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  
  pinMode(light, OUTPUT);
}

void loop()
{
  int code = ir.readIR();
  if(code != -1)
  {
    switch(code)
    {
     case -9661 : AllAllOff(); break;
     case -8651 : AllOff(r1); break;
     case -9139 : AllOff(r2); break;
     case -9159 : AllOff(r3); break;
     case -9181 : AllOff(y4); break;
     case -9681 : AllOff(y5); break;
     case -9703 : AllOff(y6); break;
     case -9205 : AllOff(g7); break;
     //case -9703 : AllOff(g8); break;
     case -9725 : AllOff(g9); break;
     
     case -9683 : a++; if(a == 5) a = 1;
         switch (a)
         {
         case 1: digitalWrite(b1, LOW);
                 digitalWrite(b2, LOW);
                 digitalWrite(b3, LOW);  break;
         case 2: digitalWrite(b1, HIGH);
                 digitalWrite(b2, LOW);
                 digitalWrite(b3, LOW);  break;
         case 3: digitalWrite(b1, LOW);
                 digitalWrite(b2, HIGH);
                 digitalWrite(b3, LOW);  break;
         case 4: digitalWrite(b1, LOW);
                 digitalWrite(b2, LOW);
                 digitalWrite(b3, HIGH); break;
         } break;
         
    case -8087 : if(li)analogWrite(light, 0); else analogWrite(light, l); li = !li; break;
    case -9137 : l+=50; if(l > 255){l = 255;} analogWrite(light, l); break;
    case -8627 : l-=50; if(l < 0){l = 0;} analogWrite(light, l); break;
    
    case -8605 : Step-=10; if(Step<0){Step = 0;}; servo.write(Step); break;
    case -9117 : Step+=10; if(Step>170){Step = 170;}; servo.write(Step); break;
    }
}}

void AllOff(int pin)
{
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(r3, LOW);
  digitalWrite(y4, LOW);
  digitalWrite(y5, LOW);
  digitalWrite(y6, LOW);
  digitalWrite(g7, LOW);
  digitalWrite(g8, LOW);
  digitalWrite(g9, LOW);
  digitalWrite(pin, HIGH);
}
void AllAllOff()
{
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(r3, LOW);
  digitalWrite(y4, LOW);
  digitalWrite(y5, LOW);
  digitalWrite(y6, LOW);
  digitalWrite(g7, LOW);
  digitalWrite(g8, LOW);
  digitalWrite(g9, LOW);
 }
