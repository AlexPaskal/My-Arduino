#define Trig 8
#define Echo 7
#define buzzer 6

void setup()
{
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(buzzer, OUTPUT);
}

int impulseTime=0; 
int distance_sm=0; 
void loop()
{
  digitalWrite(Trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(Trig, LOW); 
  impulseTime=pulseIn(Echo, HIGH);
  distance_sm=impulseTime/58; 
  
  if(distance_sm<5 || distance_sm>40) noTone(buzzer);
  else{
 int sound = map(distance_sm, 5, 40, 100, 1000);
 
 tone(buzzer, sound);
  }
  
  delay(10);
}
