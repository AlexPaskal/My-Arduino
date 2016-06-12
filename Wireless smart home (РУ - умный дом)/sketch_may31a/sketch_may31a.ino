#include <Servo.h>
Servo servo;

#define buzzer 11

byte TimeHour = 0;
byte TimeMinute = 0;

const int A = 3;
const int B = 5;
const int C = 2;
const int D = 4;

const int WhLed = 6;
const int BlLed = 7;

boolean WhL = false;
boolean BlL = false;
boolean srv = false;

void setup()
{
  servo.attach(9);
  servo.write(20);
  Serial.begin(9600);
  
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(WhLed, OUTPUT);
  pinMode(BlLed, OUTPUT);
}


void loop()
{ 
  if(Serial.available() >= 2){     
      TimeHour = Serial.read();
      TimeMinute = Serial.read();}
   if(digitalRead(A) == HIGH)//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
   {
    // 
       tone(buzzer, 500);
       delay(1000);
       noTone(buzzer);
       delay(1000);
       for (int i = 1; i<=TimeHour; i++)//HOUR
       {
       tone(buzzer, 800);
       delay(500);
       noTone(buzzer);
       delay(500);
       }
       delay(500);
       tone(buzzer, 500);
       delay(1000);
       noTone(buzzer);
       delay(1000);
       tone(buzzer, 500);
       delay(1000);
       noTone(buzzer);
       delay(1000);
       for (int i = 1; i<=(TimeMinute/10); i++)//10minute
       {
       tone(buzzer, 800);
       delay(500);
       noTone(buzzer);
       delay(500);
       }     
       delay(500);
       tone(buzzer, 500);
       delay(1000);
       noTone(buzzer);
       delay(1000);
       for (int i = 1; i<=(TimeMinute%10); i++)//minute
       {
       tone(buzzer, 800);
       delay(500);
       noTone(buzzer);
       delay(500);
       }     
       delay(500);
       tone(buzzer, 500);
       delay(1000);
       noTone(buzzer);  
    // }
     while(digitalRead(A) == HIGH);
   }
   if(digitalRead(B) == HIGH)//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
   {
      if(srv == false)
    {for(int i = 20; i<=110; i++)
    {servo.write(i);
    delay(5);}
    }
      else
    {for(int i = 110; i>=20; i--)
    {
    servo.write(i);
    delay(5);
    } }
    srv = !srv;
    while(digitalRead(B) == HIGH); 
   }
 
  if(digitalRead(C) == HIGH)//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
  {
  digitalWrite(WhLed, WhL);
  WhL = !WhL;
  while(digitalRead(C) == HIGH);
  }
  if(digitalRead(D) == HIGH)//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
  {
  digitalWrite(BlLed, BlL);
  BlL = !BlL;
  while(digitalRead(D) == HIGH);
  }
  
  delay(100);
}
