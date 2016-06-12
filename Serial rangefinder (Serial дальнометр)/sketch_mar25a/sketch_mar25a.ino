#define Trig 8
#define Echo 7
void setup()
{
    Serial.begin(9600);
  
  pinMode(Trig, OUTPUT); //инициируем как выход 
  pinMode(Echo, INPUT); //инициируем как вход   
}
float impulseTime=0; 
float distance_sm=0; 
byte top = 250;

void loop()
{
  digitalWrite(Trig, HIGH); 
  delayMicroseconds(10);  
  digitalWrite(Trig, LOW); 
  impulseTime=pulseIn(Echo, HIGH);
  distance_sm=impulseTime/58; 
  if(distance_sm<=55)
  top = map(distance_sm, 5, 55, 200, 1);
  else top = 250;
  Serial.flush();
  Serial.write(top);
  
  delay(100);
}
