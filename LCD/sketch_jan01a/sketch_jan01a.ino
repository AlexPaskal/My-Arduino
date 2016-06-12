//Library by David Mellis, Limor Fried, and Tom Igoe
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
byte One[8] = {
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111
};
byte Two[8] = {
  B10111,
  B10111,
  B10111,
  B10111,
  B10111,
  B10111,
  B10111,
  B10111
};
byte Three[8] = {
  B11011,
  B11011,
  B11011,
  B11011,
  B11011,
  B11011,
  B11011,
  B11011
};
byte Four[8] = {
  B11101,
  B11101,
  B11101,
  B11101,
  B11101,
  B11101,
  B11101,
  B11101
};
byte Five[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};
byte All[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup()
{
  pinMode(9, OUTPUT);
  analogWrite(9, 10);
  //
  lcd.createChar(2, One);
  lcd.createChar(3, Two);
  lcd.createChar(4, Three);
  lcd.createChar(5, Four);
  lcd.createChar(6, Five);
  lcd.createChar(10, All);  
  //
  lcd.begin(16, 2);
  lcd.print("Hello from Alex!");
  lcd.setCursor(1, 0);
   for(int i = 0; i<=15; i++)
  {
      lcd.setCursor(i, 1);
   lcd.write(10);
  }
}

void loop()
{
  for(int i=0; i<=15; i++)
  {
      lcd.setCursor(i, 1);
   lcd.write(2);
   delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(3);
   delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(4);
   delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(5);
  delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(6);
 delay(200); 
       lcd.setCursor(i, 1);
   lcd.write(10);
 //delay(200); 
  }

  for(int i = 15; i>=0; i--)
  {
          lcd.setCursor(i, 1);
   lcd.write(10);
   delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(6);
   delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(5);
   delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(4);
   delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(3);
   delay(200); 
      lcd.setCursor(i, 1);
   lcd.write(2);
   //delay(200); 
  }
}
