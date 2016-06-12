//Library by David Mellis, Limor Fried, and Tom Igoe
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
#define buz 6


int tmp = 0;
int var = 0; //variant
int kn = 2;
int knOO = 8;
int light = 3;
boolean pr = true;
boolean OO = true;
boolean prOO = true;


void setup()
{
  //pinMode(buz, OUTPUT);
  lcd.begin(16, 2);
  pinMode(9, OUTPUT);
  analogWrite(9, 10);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(kn, INPUT);
  pinMode(knOO, INPUT);
  pinMode(light, INPUT);  
}

void loop()
{
 int tmS = analogRead(tmp);
  
 float volt = (tmS/1024.0)*5.0;
 float TMP = (volt - .5)*100;

 float Celsius = TMP;
 float Farengeit = ((Celsius * 9)/5) + 32;
 float Kelvin = (Celsius + 273.15);
 
 int lt = analogRead(light);
 int svet = map(lt, 0, 1023, 0, 100);
  
  if(digitalRead(kn) == HIGH) {
    if(pr == true){
    pr = false;
    tone(buz, 800); delay(100); noTone(buz);
    
     if (var == 3) var = -1;
     var = var+1;
}}
  else pr = true;
 
if(digitalRead(knOO) == HIGH)
{
  if(prOO == true){
    tone(buz, 800); delay(100); noTone(buz);
 prOO = false;
  if (OO == true) OO = false;
  else if (OO == false) OO = true;  
  
}}
 else prOO = true;

 if (var == 0 || OO == false)
 {
   lcd.clear();
   analogWrite(9, 1023);
   digitalWrite(7, LOW);
 } 
 if(var != 0 && OO == true){
    lcd.clear();
  lcd.setCursor(5, 0);
 lcd.print("Hello!");
 analogWrite(9, 10);
 digitalWrite(7, HIGH);  
   
 if (var == 1)
 {
   lcd.setCursor(0, 1);
   lcd.print(Celsius);
   lcd.write(B11011111); lcd.print("C");
 } 
 if (var == 2)
{
   lcd.setCursor(0, 1);
   lcd.print(Farengeit);
   lcd.write(B11011111); lcd.print("F");
 } 
 if (var == 3)
 {
   lcd.setCursor(0, 1);
   lcd.print(Kelvin);
   lcd.write(B11011111); lcd.print("K");
 }  
 lcd.setCursor(10, 1);
 lcd.print(svet);
 lcd.write(B0100101);
 lcd.print("Lt");
 }
 
 delay(500);
}
