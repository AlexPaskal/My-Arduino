//Library by David Mellis, Limor Fried, and Tom Igoe
#include <LiquidCrystal.h>
#define buzzer 6
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
byte NoteNote[8] = {
B00010,
B00011,
B00010,
B00010,
B01110,
B10010,
B01100,
B00000 };

int potMet = 3;
//int time = 100;  //vremia zaderzki. iznachalno -- 100;

void setup()
{
// LCD
  pinMode(buzzer, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  analogWrite(9, 10);
  digitalWrite(7, HIGH);
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.write("Welcome!");
  lcd.createChar(1, NoteNote);
// LCD
}

void loop()
{
  int PotM = analogRead(potMet);
    int value = map(PotM, 0, 1023, 1, 8);
if (value == 1)
{
 lcd.setCursor(0, 1);
 lcd.write(B11111110);
 lcd.setCursor(1, 1);
 lcd.write(B11111110);
 lcd.setCursor(2, 1);
 lcd.write(B11111110);
 noTone(buzzer); 
 }
 else if (value == 2)          // C
 {
 lcd.setCursor(0, 1);
 lcd.write(byte(1)); 
 lcd.print(" C"); 
 tone(buzzer, 262);
 }
 else if (value == 3)          // D
 {
 lcd.setCursor(0, 1);
 lcd.write(byte(1)); 
 lcd.print(" D"); 
 tone(buzzer, 294);
 }
 else if (value == 4)          // E
 {
 lcd.setCursor(0, 1);
 lcd.write(byte(1)); 
 lcd.print(" E"); 
 tone(buzzer, 330);
 }
 else if (value == 5)          // F
 {
 lcd.setCursor(0, 1);
 lcd.write(byte(1)); 
 lcd.print(" F"); 
 tone(buzzer, 349);
 }  
 else if (value == 6)          // G
 {
 lcd.setCursor(0, 1);
 lcd.write(byte(1)); 
 lcd.print(" G"); 
 tone(buzzer, 392);
 }  
 else if (value == 7)          // A
 {
 tone(buzzer, 440);
 lcd.setCursor(0, 1);
 lcd.write(byte(1)); 
 lcd.print(" A");
 tone(buzzer, 440);
 }  
 else if (value == 8)          // H
 {
 lcd.setCursor(0, 1);
 lcd.write(byte(1)); 
 lcd.print(" H"); 
 tone(buzzer, 494);
 }  
 else if (value>8) {lcd.setCursor(0, 0); lcd.print("Bad") ; }

 delay(500);
 
}
