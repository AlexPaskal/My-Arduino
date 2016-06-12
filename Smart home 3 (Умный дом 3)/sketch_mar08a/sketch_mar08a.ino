
int buzzer = 6; 
int button = 2;
int datchik = 5;
int photo = 0;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  pinMode(datchik, INPUT);
  pinMode(photo, INPUT);
  
}

void loop()
{
while(analogRead(photo) < 800) ;

if(digitalRead(datchik) == LOW) {
 for(int i=0; i<=300; i++){
     if(digitalRead(datchik) == HIGH) goto endPr;
   delay(100);  }
                              tone(buzzer, 800); delay(500); noTone(buzzer); delay(200);
                              tone(buzzer, 800); delay(200); noTone(buzzer); delay(200);
                              tone(buzzer, 800); delay(300); noTone(buzzer);
 for(int i=0; i<=300; i++){
     if(digitalRead(datchik) == HIGH || digitalRead(button) == HIGH) goto endPr;
   delay(100);   
}
while(digitalRead(button) == LOW)
{
tone(buzzer, 1000);    
}
 noTone(buzzer);
endPr:;
};}

