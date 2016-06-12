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
//
//const int rel1 = 42;
//const int rel2 = 43;
//const int rel3 = 44;
//const int rel4 = 45;

const int b1 = 23;
const int b2 = 25;
const int b3 = 27;

const int Rl = 29;
const int Rl2 = 31;

const int light = 7;

int a = 0;
int l = 255;
boolean li = false;
int Step = 90;
boolean Anime = false;
unsigned long Mil = 0;
boolean Relay = true;
boolean Relay2 = true;
Servo servo;
IR ir;

//   volatile boolean Aa = true;
//  volatile boolean Bb = true;
// volatile boolean Cc = true;
//volatile boolean Dd = true;
void setup()
{
//  attachInterrupt(5, Arelay, RISING);
//  attachInterrupt(4, Brelay, RISING);
//  attachInterrupt(3, Crelay, RISING);
//  attachInterrupt(2, Drelay, RISING);
  
  servo.attach(10);
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
  
  pinMode(Rl, OUTPUT);
  pinMode(Rl2, OUTPUT);

//  
//  pinMode(rel1, OUTPUT);
//  pinMode(rel2, OUTPUT);
//  pinMode(rel3, OUTPUT);
//  pinMode(rel4, OUTPUT);
  
  pinMode(light, OUTPUT);

//  digitalWrite(rel1, HIGH);
//  digitalWrite(rel2, HIGH);
//  digitalWrite(rel3, HIGH);
//  digitalWrite(rel4, HIGH);
digitalWrite(Rl, HIGH);
digitalWrite(Rl2, HIGH);
}

void loop()
{
  //digitalWrite(r1, HIGH);
  int code = ir.readIR();
  if(code != -1)
  {
    switch(code)
    {
     case -9661 : if(Anime == false){AllAllOff();} break;
     case -8651 : if(Anime == false){AllOff(r1);} break;
     case -9139 : if(Anime == false){AllOff(r2);} break;
     case -9159 : if(Anime == false){AllOff(r3);} break;
     case -9181 : if(Anime == false){AllOff(y4);} break;
     case -9681 : if(Anime == false){AllOff(y5);} break;
     case -9703 : if(Anime == false){AllOff(y6);} break;
     case -9205 : if(Anime == false){AllOff(g7);} break;
     //case -9703 : if(Anime == false){AllOff(g8);} break;
     case -9725 : if(Anime == false){AllOff(g9);} break;
     
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
    
    case -8605 : Step-=20; if(Step<10){Step = 10;} servo.write(Step); break;
    case -9117 : Step+=20; if(Step>170){Step = 170;} servo.write(Step); break;
    case -9097 : Anime = !Anime; Mil = 0; break;
    case -8585 : Relay2 = !Relay2; digitalWrite(Rl2, Relay2); break;
    case -8567 : Relay = !Relay; digitalWrite(Rl, Relay); break;
    }
}
while(Anime == true){
 if(Mil == millis()) AllAllOff();
 if(Mil+100 == millis()) AllOff(r1);
 if(Mil+200 == millis()) AllOff(r2);
 if(Mil+300 == millis()) AllOff(r3);
 if(Mil+400 == millis()) AllOff(y4);  
 if(Mil+500 == millis()) AllOff(y5);  
 if(Mil+600 == millis()) AllOff(y6);  
 if(Mil+700 == millis()) AllOff(g7);  
 if(Mil+800 == millis()) AllOff(g8);  
 if(Mil+900 == millis()) AllOff(g9);  
 if(Mil+1000 == millis() || Mil == 0) Mil = millis();
   int code = ir.readIR();
 if(code == -9097) {Anime = !Anime; AllAllOff();}
}

}

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
// 
// void Arelay()
// {
//  Aa = !Aa;
// digitalWrite(rel1, Aa); 
// }
// void Brelay()
// {
//  Bb = !Bb;
// digitalWrite(rel2, Bb); 
// }
// void Crelay()
// {
//  Cc = !Cc;
// digitalWrite(rel3, Cc); 
// }
// void Drelay()
// {
//  Dd = !Dd;
// digitalWrite(rel4, Dd); 
// }
