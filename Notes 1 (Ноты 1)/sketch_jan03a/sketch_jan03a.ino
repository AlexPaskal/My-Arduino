//Library by David Mellis, Limor Fried, and Tom Igoe
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
//
byte Note210[8] = {
B00011,
B00010,
B00010,
B00010,
B01110,
B10010,
B10010,
B01100
};
byte Note220[8] = {
B00011,
B00010,
B00010,
B00010,
B01110,
B10010,
B01100,
B00000
} ;
byte Note320[8] = {
B00010,
B00011,
B00010,
B00010,
B01110,
B10010,
B01100,
B00000
} ;
byte Note310[8] = {
B00010,
B00011,
B00010,
B00010,
B01110,
B10010,
B10010,
B01100
};
byte Note110[8] = {
B00000,
B00000,
B01111,
B01001,
B01001,
B01001,
B11011,
B00000
};
byte Note120[8] = {
B00000,
B00011,
B01101,
B01001,
B01001,
B01011,
B11000,
B00000
};

  
void setup()
{
  pinMode(9, OUTPUT);
  analogWrite(9, 10);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);  
  ////////////////////////////////////////////////////////////////
  lcd.createChar(1, Note210);
  lcd.createChar(2, Note220);
  lcd.createChar(3, Note110);
  lcd.createChar(4, Note310);
  lcd.createChar(5, Note320);
  lcd.createChar(6, Note120);
  ////////////////////////////////////////////////////////////////
  lcd.begin(16, 2);
  //lcd.print("Hello from Alex!");
  ////////////////////////////////////////////////////////////////
  //lcd.setCursor(0, 1);
  lcd.write(1); 
  lcd.write(2);
  lcd.write(3); 
  lcd.write(6); 
  lcd.write(4);
  lcd.write(5); 
  
}

void loop()
{
///
}
