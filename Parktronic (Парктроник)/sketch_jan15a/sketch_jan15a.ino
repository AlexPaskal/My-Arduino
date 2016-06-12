#define Piezo 6
#define Trig 8
#define Echo 7

void setup()
{
// Serial.begin(9600); 
  
 pinMode(Trig, OUTPUT);
 pinMode(Echo, INPUT); 
 pinMode(Piezo, OUTPUT); 
}

float IMPtime = 0;
float distanceCM = 0;

void loop()
{
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  IMPtime=pulseIn(Echo, HIGH);
  distanceCM=IMPtime/58;
  
  if(distanceCM<10) {tone(Piezo, 1000);
                      delay(200);}
  if(distanceCM>10 && distanceCM<50) 
                     {tone(Piezo, 1000);
                      delay(200);
                      noTone(Piezo);
                      delay(200);  }
  if(distanceCM>50)  {noTone(Piezo);
                      delay(200);}  
                      

}
