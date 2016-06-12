const int D0 = 4 ; // BBBB 
const int D1 = 5 ; // DDDD // OFF white led 
const int D2 = 6 ; // AAAA 
const int D3 = 7 ; // CCCC // ON white led 

const int WLed = 8;
const int RLed = 11;
const int BLed = 12;
const int GLed = 13;
const int buzzer = 9;

const int sensor = 10;

void setup()
{
  pinMode(WLed, OUTPUT);
  pinMode(RLed, OUTPUT);
  pinMode(GLed, OUTPUT);
  pinMode(BLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(D0, INPUT);
  pinMode(D2, INPUT);
  pinMode(sensor, INPUT);
  attachInterrupt(0, On, RISING); // pin 7 // ON white led
  attachInterrupt(1, Off, RISING); // pin 5 // OFF white led
  
  Serial.begin(9600);
}
 int danger = 0;
void loop()
{
  Start:
     digitalWrite(GLed, HIGH);
   delay(2000);
   digitalWrite(GLed, LOW);
   
  while(digitalRead(D2) == LOW) ;
   digitalWrite(GLed, HIGH);
   delay(500);
   digitalWrite(GLed, LOW);
   do
   {
     unsigned long a = 0;
     a = pulseIn(sensor, LOW, 10000000);
     Serial.println(a);
   } while (a <10000000);
  // if(a > 1000) digitalWrite(RLed, HIGH);
   
//  while(digitalRead(sensor) == LOW) 
//    { if(digitalRead(D0) == HIGH) goto Start; }
//    digitalWrite(GLed, HIGH);
//    delay(1000);
//  digitalWrite(GLed, LOW);
//    unsigned long mil = millis();
//    
//         while(digitalRead(sensor) == HIGH) 
//    { if(digitalRead(D0) == HIGH) goto Start; 
//      if(mil+10000 < millis()) goto Start;} 
//    
//    mil = millis();
//    
//     while(digitalRead(sensor) == LOW) 
//    { if(digitalRead(D0) == HIGH) goto Start; 
//      if(mil+10000 < millis()) goto Start;} 
//  ////////////////////////////////////////////////////////////
//    while(digitalRead(D0) == LOW)
//    {
//      if (millis() % 1000 < 500) 
//      {
//        digitalWrite(BLed, LOW);
//        digitalWrite(RLed, HIGH);
//        tone(buzzer, 800);
//      }
//      if (millis() % 1000 >= 500) 
//      {
//        digitalWrite(RLed, LOW);
//        digitalWrite(BLed, HIGH);
//        noTone(buzzer);
//      }
//  } 
  
  digitalWrite(RLed, LOW);
  digitalWrite(BLed, LOW);
  noTone(buzzer);
}

void On()
{
  digitalWrite(WLed, HIGH);
}
void Off()
{
  digitalWrite(WLed, LOW);
}
