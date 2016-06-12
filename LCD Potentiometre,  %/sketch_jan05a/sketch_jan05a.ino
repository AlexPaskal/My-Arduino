//Library by David Mellis, Limor Fried, and Tom Igoe
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

int time = 100; // vremia zaderzki;

void setup()
{
  pinMode(9, OUTPUT);
  analogWrite(9, 10);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  
  lcd.begin(16, 2);
  lcd.print("Hello from Alex!");
  lcd.setCursor(1, 0);  
}

void loop()
{
int valM = analogRead(3);
int valP = map(valM, 0, 1023, 0, 100);
lcd.setCursor(0, 1); lcd.write(B11111110);
lcd.setCursor(1, 1); lcd.write(B11111110);
lcd.setCursor(2, 1); lcd.write(B11111110);
lcd.setCursor(3, 1); lcd.write(B11111110);
lcd.setCursor(0, 1);
lcd.print(valP);
lcd.write(B00100101);
delay(time);

}
