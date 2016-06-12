#define Trig 3
#define Echo 4
int buzzer = 6; 
int datchik = 5;
int photo = 0;


void setup()
{
  pinMode(Trig, OUTPUT); 
  pinMode(Echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(datchik, INPUT);
  pinMode(photo, INPUT);
}

float impulseTime=0; 
float distance_sm=0; 

void loop()
{
  digitalWrite(Trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(Trig, LOW); 
  impulseTime=pulseIn(Echo, HIGH); 
  distance_sm=impulseTime/58; 
  
  if(distance_sm <= 50)
  {
    delay(10000);
     for(int i=0; i<=100; i++){
     if(digitalRead(datchik) == LOW && analogRead(photo) > 900)
     {
      while(analogRead(photo) > 900 && digitalRead(datchik) == LOW) 
      {tone(buzzer, 900); delay(800); noTone(buzzer); delay(200);
       tone(buzzer, 900); delay(300); noTone(buzzer); delay(200);}
     } 
   delay(100);  
 }
  }
  
  delay(100);
}
