#define R1 22
#define R2 23
#define R3 24
#define R4 25

#define Y1 26
#define Y2 27
#define Y3 28
#define Y4 29

#define G1 30
#define G2 31
#define G3 32
#define G4 33
///
#define R5 34
#define R6 35
#define R7 36

#define Y5 37
#define Y6 38
#define Y7 39

#define G5 40
#define G6 41
#define G7 42


#define LightSensor 15
#define LightLed 10

/////////////////////////////////////////////////////////////////
void setup()
{
  //////
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(Y3, OUTPUT);
  pinMode(Y4, OUTPUT);
  pinMode(Y5, OUTPUT);
  pinMode(Y6, OUTPUT);
  pinMode(Y7, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(G3, OUTPUT);
  pinMode(G4, OUTPUT);
  pinMode(G5, OUTPUT);
  pinMode(G6, OUTPUT);
  pinMode(G7, OUTPUT);
  
  pinMode(LightLed, OUTPUT);
  digitalWrite(LightLed, LOW);
  
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);
  digitalWrite(R5, HIGH);
  digitalWrite(R6, HIGH);
  digitalWrite(R7, HIGH);
  //
  digitalWrite(Y1, LOW);
  digitalWrite(Y2, LOW);
  digitalWrite(Y3, LOW);
  digitalWrite(Y4, LOW);
  digitalWrite(Y5, LOW);
  digitalWrite(Y6, LOW);
  digitalWrite(Y7, LOW);
  //
  digitalWrite(G1, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(G3, LOW);
  digitalWrite(G4, LOW);
  digitalWrite(G5, LOW);
  digitalWrite(G6, LOW);
  digitalWrite(G7, LOW);
  //
}
/////////////////////////////////////////////////////////////////
byte LS1 = 1;
int dR1 = 3000;
int dY1_1 = 1000;
int dG1 = 2000;
int dY1_2 = 1000;
boolean a1 = true;
unsigned long UL1;
//
byte LS2 = 1;
int dR2 = 1000;
int dY2_1 = 300;
int dG2 = 500;
int dY2_2 = 300;
boolean a2 = true;
unsigned long UL2;
//
byte LS3 = 3;
int dR3 = 2000;
int dY3_1 = 1000;
int dG3 = 3000;
int dY3_2 = 1000;
boolean a3 = true;
unsigned long UL3;
//
byte LS4 = 1;
int dR4 = 60000;
int dY4_1 = 10000;
int dG4 = 60000;
int dY4_2 = 10000;
boolean a4 = true;
unsigned long UL4;
//
byte LS5 = 3;
int dR5 = 1000;
int dY5_1 = 1000;
int dG5 = 1000;
int dY5_2 = 1000;
boolean a5 = true;
unsigned long UL5;
//
byte LS6 = 1;
int dR6 = 30000;
int dY6_1 = 3000;
int dG6 = 30000;
int dY6_2 = 3000;
boolean a6 = true;
unsigned long UL6;
//
byte LS7 = 3;
int dR7 = 30000;
int dY7_1 = 3000;
int dG7 = 30000;
int dY7_2 = 3000;
boolean a7 = true;
unsigned long UL7;
//
unsigned long Mil;

const int Porog = 500;
/////////////////////////////////////////////////////////////////
void loop()
{
 Mil = millis();
switch(LS1)
{
 case 1 :  if(a1) {UL1 = Mil; a1 = false;} 
AllOff(R1, Y1, G1);
 if(Mil == UL1+dR1){LS1 = 2; a1 = true;} break;
 
 case 2 : if(a1) {UL1 = Mil; a1 = false;} 
AllOff(Y1, R1, G1);
 if(Mil == UL1+dY1_1){LS1 = 3; a1 = true;} break;
 
 case 3 : if(a1) {UL1 = Mil; a1 = false;} 
AllOff(G1, Y1, R1);
 if(Mil == UL1+dG1){LS1 = 4; a1 = true;} break;
 
 case 4 : if(a1) {UL1 = Mil; a1 = false;} 
AllOff(Y1, R1, G1);
 if(Mil == UL1+dY1_1){LS1 = 1; a1 = true;} break;
}
//////////////////////////
switch(LS2)
{
 case 1 :  if(a2) {UL2 = Mil; a2 = false;} 
AllOff(R2, Y2, G2);
 if(Mil == UL2+dR2){LS2 = 2; a2 = true;} break;
 
 case 2 : if(a2) {UL2 = Mil; a2 = false;} 
AllOff(Y2, R2, G2);
 if(Mil == UL2+dY2_1){LS2 = 3; a2 = true;} break;
 
 case 3 : if(a2) {UL2 = Mil; a2 = false;} 
AllOff(G2, Y2, R2);
 if(Mil == UL2+dG2){LS2 = 4; a2 = true;} break;
 
 case 4 : if(a2) {UL2 = Mil; a2 = false;} 
AllOff(Y2, R2, G2);
 if(Mil == UL2+dY2_1){LS2 = 1; a2 = true;} break;
}
//////////////////////////
switch(LS3)
{
 case 1 :  if(a3) {UL3 = Mil; a3 = false;} 
AllOff(R3, Y3, G3);
 if(Mil == UL3+dR3){LS3 = 2; a3 = true;} break;
 
 case 2 : if(a3) {UL3 = Mil; a3 = false;} 
AllOff(Y3, R3, G3);
 if(Mil == UL3+dY3_1){LS3 = 3; a3 = true;} break;
 
 case 3 : if(a3) {UL3 = Mil; a3 = false;} 
AllOff(G3, Y3, R3);
 if(Mil == UL3+dG3){LS3 = 4; a3 = true;} break;
 
 case 4 : if(a3) {UL3 = Mil; a3 = false;} 
AllOff(Y3, R3, G3);
 if(Mil == UL3+dY3_1){LS3 = 1; a3 = true;} break;
}
//////////////////////////
switch(LS4)
{
 case 1 :  if(a4) {UL4 = Mil; a4 = false;} 
AllOff(R4, Y4, G4);
 if(Mil == UL4+dR4){LS4 = 2; a4 = true;} break;
 
 case 2 : if(a4) {UL4 = Mil; a4 = false;} 
AllOff(Y4, R4, G4);
 if(Mil == UL4+dY4_1){LS4 = 3; a4 = true;} break;
 
 case 3 : if(a4) {UL4 = Mil; a4 = false;} 
AllOff(G4, Y4, R4);
 if(Mil == UL4+dG4){LS4 = 4; a4 = true;} break;
 
 case 4 : if(a4) {UL4 = Mil; a4 = false;} 
AllOff(Y4, R4, G4);
 if(Mil == UL4+dY4_1){LS4 = 1; a4 = true;} break;
}
//////////////////////////
switch(LS5)
{
 case 1 :  if(a5) {UL5 = Mil; a5 = false;} 
AllOff(R5, Y5, G5);
 if(Mil == UL5+dR5){LS5 = 2; a5 = true;} break;
 
 case 2 : if(a5) {UL5 = Mil; a5 = false;} 
AllOff(Y5, R5, G5);
 if(Mil == UL5+dY5_1){LS5 = 3; a5 = true;} break;
 
 case 3 : if(a5){UL5 = Mil; a5 = false;} 
AllOff(G5, Y5, R5);
 if(Mil == UL5+dG5){LS5 = 4; a5 = true;} break;
 
 case 4 : if(a5) {UL5 = Mil; a5 = false;} 
AllOff(Y5, R5, G5);
 if(Mil == UL5+dY5_1){LS5 = 1; a5 = true;} break;
}
//////////////////////////
switch(LS6)
{
 case 1 :  if(a6) {UL6 = Mil; a6 = false;} 
AllOff(R6, Y6, G6);
 if(Mil == UL6+dR6){LS6 = 2; a6 = true;} break;
 
 case 2 : if(a6) {UL6 = Mil; a6 = false;} 
AllOff(Y6, R6, G6);
 if(Mil == UL6+dY6_1){LS6 = 3; a6 = true;} break;
 
 case 3 : if(a6) {UL6 = Mil; a6 = false;} 
AllOff(G6, Y6, R6);
 if(Mil == UL6+dG6){LS6 = 4; a6 = true;} break;
 
 case 4 : if(a6) {UL6 = Mil; a6 = false;} 
AllOff(Y6, R6, G6);
 if(Mil == UL6+dY6_1){LS6 = 1; a6 = true;} break;
}
//////////////////////////
switch(LS7)
{
 case 1 :  if(a7) {UL7 = Mil; a7 = false;} 
AllOff(R7, Y7, G7);
 if(Mil == UL7+dR7){LS7 = 2; a7 = true;} break;
 
 case 2 : if(a7) {UL7 = Mil; a7 = false;} 
AllOff(Y7, R7, G7);
 if(Mil == UL7+dY7_1){LS7 = 3; a7 = true;} break;
 
 case 3 : if(a7) {UL7 = Mil; a7 = false;} 
AllOff(G7, Y7, R7);
 if(Mil == UL7+dG7){LS7 = 4; a7 = true;} break;
 
 case 4 : if(a7) {UL7 = Mil; a7 = false;} 
AllOff(Y7, R7, G7);
 if(Mil == UL7+dY7_1){LS7 = 1; a7 = true;} break;
}
//////////////////////////
if(Mil % 500 == 0)
{
  if(analogRead(LightSensor) < Porog)
    digitalWrite(LightLed, HIGH);
    else digitalWrite(LightLed, LOW);
}
//////////////////////////
}
/////////////////////////////////////////////////////////////////
void AllOff(int on, int off1, int off2)
{
  digitalWrite(off1, LOW);
  digitalWrite(off2, LOW);
  digitalWrite(on, HIGH);
}
