//Library by David Mellis, Limor Fried, and Tom Igoe

#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 6, 9, 10, 11, 12);

void setup()
{
lcd.begin(16, 2)  ;
lcd.print("!Happy New Year!")  ;
}

void loop()
{
while(Serial.available() == 0);
char val = Serial.read();
lcd.print(val)  ;

}
