
#define buzzer 10

boolean debounce(int Pin, boolean last)
{
 boolean current = digitalRead(Pin);
    if(current != last)
      {
        delay(5);
        current = digitalRead(Pin);
      } 
  return(current);    
}

int row1 = 4; //строки
int row2 = 5; //выход
int row3 = 6;
int row4 = 7;

int col1 = 9; //столбцы
int col2 = 8; //вход (стягивать)
int col3 = 2;
int col4 = 3;

int led = 13;
int sensor = 11;

boolean side = HIGH; //High-inside; low-outside
boolean enter = LOW;

boolean currentButton = LOW;

boolean lastButton1 = LOW;
boolean lastButton2 = LOW;
boolean lastButton3 = LOW;
boolean lastButton4 = LOW;
boolean lastButton5 = LOW;
boolean lastButton6 = LOW;
boolean lastButton7 = LOW;
boolean lastButton8 = LOW;
boolean lastButton9 = LOW;
boolean lastButton10 = LOW;
boolean lastButton11 = LOW;
boolean lastButton12 = LOW;
boolean lastButton13 = LOW;
boolean lastButton14 = LOW;
boolean lastButton15 = LOW;
boolean lastButton16 = LOW;

String key = "";

void setup()
{
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);

  pinMode(col1, INPUT);  
  pinMode(col2, INPUT);  
  pinMode(col3, INPUT);  
  pinMode(col4, INPUT);  
  
  pinMode(buzzer, OUTPUT);
  
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop()
{ 
  digitalWrite(row1, HIGH);
  if(debounce(col1, lastButton1) == HIGH && lastButton1 == LOW) 
      {key = key + "1";    tone(buzzer, 800); delay(100); noTone(buzzer);} 
       lastButton1 = debounce(col1, lastButton1);
   if(debounce(col2, lastButton2) == HIGH && lastButton2 == LOW) 
      {key = key + "2";    tone(buzzer, 800); delay(100); noTone(buzzer);} 
   lastButton2 = debounce(col2, lastButton2);
  if(debounce(col3, lastButton3) == HIGH && lastButton3 == LOW) 
      {key = key + "3";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton3 = debounce(col3, lastButton3);
    if(debounce(col4, lastButton4) == HIGH && lastButton4 == LOW) 
      {key = key + "A";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton4 = debounce(col4, lastButton4); 
  digitalWrite(row1, LOW);   
   
  digitalWrite(row2, HIGH);
  if(debounce(col1, lastButton5) == HIGH && lastButton5 == LOW) 
      {key = key + "4";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton5 = debounce(col1, lastButton5);
  if(debounce(col2, lastButton6) == HIGH && lastButton6 == LOW) 
      {key = key + "5";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton6 = debounce(col2, lastButton6);
  if(debounce(col3, lastButton7) == HIGH && lastButton7 == LOW) 
      {key = key + "6";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton7 = debounce(col3, lastButton7);
  if(debounce(col4, lastButton8) == HIGH && lastButton8 == LOW) 
      {key = key + "B";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton8 = debounce(col4, lastButton8); 
  digitalWrite(row2, LOW); 
   
  digitalWrite(row3, HIGH);
  if(debounce(col1, lastButton9) == HIGH && lastButton9 == LOW) 
      {key = key + "7";    tone(buzzer, 800); delay(100); noTone(buzzer);}
       lastButton9 = debounce(col1, lastButton9);
   if(debounce(col2, lastButton10) == HIGH && lastButton10 == LOW) 
      {key = key + "8";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton10 = debounce(col2, lastButton10);
  if(debounce(col3, lastButton11) == HIGH && lastButton11 == LOW) 
      {key = key + "9";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton11 = debounce(col3, lastButton11);
    if(debounce(col4, lastButton12) == HIGH && lastButton12 == LOW) 
      {key = key + "C";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton12 = debounce(col4, lastButton12);    
  digitalWrite(row3, LOW); 
   
  digitalWrite(row4, HIGH);
  if(debounce(col1, lastButton13) == HIGH && lastButton13 == LOW) //*
      {key = "";    tone(buzzer, 800); delay(100); noTone(buzzer);}
       lastButton13 = debounce(col1, lastButton13);
   if(debounce(col2, lastButton14) == HIGH && lastButton14 == LOW) 
      {key = key + "0";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton14 = debounce(col2, lastButton14);
  if(debounce(col3, lastButton15) == HIGH && lastButton15 == LOW) //#
      {enter=HIGH;    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton15 = debounce(col3, lastButton15);
    if(debounce(col4, lastButton16) == HIGH && lastButton16 == LOW) 
      {key = key + "D";    tone(buzzer, 800); delay(100); noTone(buzzer);}
   lastButton16 = debounce(col4, lastButton16);   
  digitalWrite(row4, LOW); 

if (enter == HIGH)
{
enter = LOW;

if(key == "1259D")
{
 side = !side;
 key = "";
if (side == LOW){digitalWrite(led, HIGH); delay(3000); digitalWrite(led, LOW);}
if (side == HIGH) digitalWrite(led, LOW);
} else if (side == LOW) digitalWrite(led, HIGH);
}

if (digitalRead(sensor) == HIGH && side == LOW) digitalWrite(led, HIGH);
}



