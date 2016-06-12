int rL = 13;
int yL = 12;
int gL = 8;
int bL = 7;

int pV = 2;

void setup(){
    Serial.begin(9600);
pinMode(rL, OUTPUT);  
pinMode(yL, OUTPUT); 
pinMode(gL, OUTPUT); 
pinMode(bL, OUTPUT); 
}

void loop(){
 int val = analogRead(pV);

  if (val<200) //1
  {
  digitalWrite(rL, HIGH);
  digitalWrite(yL, LOW);
  digitalWrite(gL, LOW);
  digitalWrite(bL, LOW);  
  }
  
  if (val>199 && val<400) //2
  {
  digitalWrite(yL, HIGH);
  digitalWrite(rL, LOW);
  digitalWrite(gL, LOW);
  digitalWrite(bL, LOW);
 }

 if (val>399 && val<600) //3
 {
  digitalWrite(gL, HIGH);
  digitalWrite(rL, LOW);
  digitalWrite(yL, LOW);
  digitalWrite(bL, LOW);  
 }

 if (val>799) //4
 {
  digitalWrite(bL, HIGH);
  digitalWrite(rL, LOW);
  digitalWrite(yL, LOW);
  digitalWrite(gL, LOW);  
 }  /*else {
  digitalWrite(rL, LOW);
  digitalWrite(yL, LOW);
  digitalWrite(gL, LOW);
  digitalWrite(bL, LOW);     
 } */
 
}
