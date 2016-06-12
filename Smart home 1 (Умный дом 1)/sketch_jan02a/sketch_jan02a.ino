//Library by David Mellis, Limor Fried, and Tom Igoe
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
#define buzzer 6

//int buzzer = 6; //piezo
int photoR = 3; //photoRezistor
int button = 2; //knopka
boolean check = false;

void setup()
{
  pinMode(buzzer, OUTPUT);
 // pinMode(photoR, INPUT);
  pinMode(button, INPUT);
  pinMode(7, OUTPUT);
 //  
 lcd.begin(16, 2);
    pinMode(9, OUTPUT);
  analogWrite(9, 10);
  digitalWrite(7, HIGH);
}

void loop()
{
  
  if(analogRead(photoR)>=800)
  {
    lcd.clear();
    digitalWrite(7, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Press the button");
    lcd.setCursor(1, 5);
    lcd.print("please"); 
//
    tone(buzzer, 500);
    delay(500);
    noTone(buzzer); 
    delay(500);
    tone(buzzer, 500);
    delay(500);
    noTone(buzzer); 
//
    for(int i=0; i<=300; i++){
      if (check == true) break;
    check = false;
    if(digitalRead(button) == HIGH)  check = true;
    delay(10);
    }//for
//  
    if (check == false){
     while(digitalRead(button) == LOW){     tone(buzzer, 1000); delay(3000); noTone(buzzer);  delay(500); }
    }
//    
    check = false;
    lcd.clear();
    lcd.setCursor(0, 4);
    lcd.write("Thank you!");
    delay(3000);
    digitalWrite(7, LOW);
    delay(177000);
  }//photoR
}
