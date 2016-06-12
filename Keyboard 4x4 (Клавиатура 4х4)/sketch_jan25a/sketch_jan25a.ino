
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
    Serial.begin(9600);
  
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);

  pinMode(col1, INPUT);  
  pinMode(col2, INPUT);  
  pinMode(col3, INPUT);  
  pinMode(col4, INPUT);  
  
  pinMode(buzzer, OUTPUT);
}

void loop()
{ 
  digitalWrite(row1, HIGH);
  if(debounce(col1, lastButton1) == HIGH && lastButton1 == LOW) 
      {key = key + "1"; Buz();} 
       lastButton1 = debounce(col1, lastButton1);
   if(debounce(col2, lastButton2) == HIGH && lastButton2 == LOW) 
      {key = key + "2"; Buz();} 
   lastButton2 = debounce(col2, lastButton2);
  if(debounce(col3, lastButton3) == HIGH && lastButton3 == LOW) 
      {key = key + "3"; Buz();}
   lastButton3 = debounce(col3, lastButton3);
    if(debounce(col4, lastButton4) == HIGH && lastButton4 == LOW) 
      {key = key + "A"; Buz();}
   lastButton4 = debounce(col4, lastButton4); 
  digitalWrite(row1, LOW);   
  delay(10);
   
  digitalWrite(row2, HIGH);
  if(debounce(col1, lastButton5) == HIGH && lastButton5 == LOW) 
      {key = key + "4"; Buz();}
   lastButton5 = debounce(col1, lastButton5);
  if(debounce(col2, lastButton6) == HIGH && lastButton6 == LOW) 
      {key = key + "5"; Buz();}
   lastButton6 = debounce(col2, lastButton6);
  if(debounce(col3, lastButton7) == HIGH && lastButton7 == LOW) 
      {key = key + "6"; Buz();}
   lastButton7 = debounce(col3, lastButton7);
  if(debounce(col4, lastButton8) == HIGH && lastButton8 == LOW) 
      {key = key + "B"; Buz();}
   lastButton8 = debounce(col4, lastButton8); 
  digitalWrite(row2, LOW); 
  delay(10);
   
  digitalWrite(row3, HIGH);
  if(debounce(col1, lastButton9) == HIGH && lastButton9 == LOW) 
      {key = key + "7"; Buz();}
       lastButton9 = debounce(col1, lastButton9);
   if(debounce(col2, lastButton10) == HIGH && lastButton10 == LOW) 
      {key = key + "8"; Buz();}
   lastButton10 = debounce(col2, lastButton10);
  if(debounce(col3, lastButton11) == HIGH && lastButton11 == LOW) 
      {key = key + "9"; Buz();}
   lastButton11 = debounce(col3, lastButton11);
    if(debounce(col4, lastButton12) == HIGH && lastButton12 == LOW) 
      {key = key + "C"; Buz();}
   lastButton12 = debounce(col4, lastButton12);    
  digitalWrite(row3, LOW); 
  delay(10);
   
  digitalWrite(row4, HIGH);
  if(debounce(col1, lastButton13) == HIGH && lastButton13 == LOW) 
      {key = key + "*"; Buz();}
       lastButton13 = debounce(col1, lastButton13);
   if(debounce(col2, lastButton14) == HIGH && lastButton14 == LOW) 
      {key = key + "0"; Buz();}
   lastButton14 = debounce(col2, lastButton14);
  if(debounce(col3, lastButton15) == HIGH && lastButton15 == LOW) 
      {key = key + "#"; Buz();}
   lastButton15 = debounce(col3, lastButton15);
    if(debounce(col4, lastButton16) == HIGH && lastButton16 == LOW) 
      {key = key + "D"; Buz();}
   lastButton16 = debounce(col4, lastButton16);   
  digitalWrite(row4, LOW); 
  delay(10);
  
  char check = Serial.read();
  
  if(check == 'c') {key = ""; Serial.println("Your string is clean!");}
  if(check == 'k') {Serial.print("Your sting now: "); Serial.println(key); }
  
  delay(100);
  

}

void Buz()
{
  tone(buzzer, 800); 
  delay(100); 
  noTone(buzzer);
}


