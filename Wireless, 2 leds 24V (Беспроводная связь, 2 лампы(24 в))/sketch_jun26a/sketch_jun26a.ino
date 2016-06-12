#define Trig 10
#define Echo 11

const int Red = 5;
const int Green = 6;

const int DSens = 7;

byte Rlev = 0;
byte Glev = 255;
boolean RG = true;

byte Mode = 3; //1 = me, 2 = Who?, 3 = anime;

const int C = 9;
const int D = 8;

void setup()
{
  attachInterrupt(0, AAA, RISING);
  attachInterrupt(1, BBB, RISING);
  Serial.begin(9600);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}

boolean Cc = true;
boolean Dd = true;

const unsigned long Anim = 100;
const unsigned long Morg = 499;
const unsigned long TimeRast = 200;
byte Clevel;
float impulseTime=0; 
float distance_sm=0; 
boolean MorgTF = true;
unsigned long Mil;
void loop()
{
//Mil = millis();
if(digitalRead(C) && Cc) {Mode = 2; Cc = false;}
if(!digitalRead(C)) Cc = true;
if(digitalRead(D) && Dd) {Mode = 3; Dd = false;}
if(!digitalRead(D)) Dd = true;

switch(Mode)
{
  case 1 : if(millis() % Morg == 0){ if(MorgTF){digitalWrite(Red, HIGH); digitalWrite(Green, HIGH);}
                                else {digitalWrite(Red, LOW); digitalWrite(Green, LOW);} MorgTF = !MorgTF; } delay(1); break;
  case 2 : if(millis() % TimeRast == 0){  digitalWrite(Trig, HIGH); delayMicroseconds(10); digitalWrite(Trig, LOW);
                                          impulseTime=pulseIn(Echo, HIGH); 
                                          distance_sm=impulseTime/58; 
                                          Clevel = map(distance_sm, 3, 100, 255, 0);
                                          digitalWrite(Red, digitalRead(DSens)); analogWrite(Green, Clevel); }break;
  case 3 : if(millis() % Anim == 0){ if(RG){Rlev++; Glev--;}else{Rlev--; Glev++;} if(Rlev == 255)RG = false; if(Rlev == 0)RG = true; 
                                 analogWrite(Red, Rlev);analogWrite(Green, Glev);} break;
  case 0 : analogWrite(Red, 0); analogWrite(Green, 0); break;
}

}

void AAA()
{
 Mode = 1;
}
void BBB()
{
 Mode = 0; 
}
