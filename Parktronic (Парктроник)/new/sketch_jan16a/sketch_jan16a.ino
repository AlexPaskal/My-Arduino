//Library by David Mellis, Limor Fried, and Tom Igoe
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
#define Trig 7
#define Echo 8

int lc_d = 9;
int x = 0;
int y = 1;
void setup()
{
  lcd.begin(16, 2);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(lc_d, OUTPUT);
}
int time = 0;
int CM = 0;
int peredacha = 0;

void loop()
{
  int x = analogRead(0);
  int y = analogRead(1);
  lcd.clear();
  digitalWrite(lc_d, HIGH);
  if(x<100 && y>400 && y<600)  peredacha = 0;
  else if(x>400 && x<600 && y<100) peredacha = 1;
  else if(x>400 && x<600 && y>900) peredacha = 2;  
  else if(y>400 && y<600 && x>900) peredacha = 3;   
  
  if(peredacha == 0) digitalWrite(lc_d, LOW);
  if(peredacha == 1){lcd.setCursor(0, 0); lcd.print("2");}
  if(peredacha == 2){lcd.setCursor(0, 0); lcd.print("1");}
  if(peredacha == 3){lcd.setCursor(0, 0); lcd.print("R");  
  
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  time = pulseIn(Echo, HIGH);
  CM = time/58;
  
  if (CM > 100.00) {lcd.setCursor(5, 1); lcd.print("NORMAL");}
  else {
  digitalWrite(lc_d, HIGH);
  lcd.setCursor(4, 0);
  lcd.print(CM); lcd.print(" cm");
  int kolvo = CM/10;
  for(int i = 0; i < kolvo; i++)
  {lcd.setCursor(i, 1);
  lcd.write(B11111111);}
  if(CM<=10){lcd.setCursor(9, 1); lcd.print("!CLOSE!");}

  }}
  
  delay(500);
}


