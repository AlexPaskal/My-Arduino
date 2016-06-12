const int volt1 = 4;
const int volt2 = 5;
const int swi = 6; //true == red; false == green !!!FOR RELAY!!!;

void setup()
{
  pinMode(volt1, OUTPUT);
  pinMode(volt2, OUTPUT);
  pinMode(swi, OUTPUT);
  digitalWrite(swi, LOW);
  digitalWrite(volt1, LOW);
  digitalWrite(volt2, LOW);  
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available() == 0) ;
  
 char Commang = Serial.read();
 if(Commang == 'G') digitalWrite(swi, HIGH);
 if(Commang == 'R') digitalWrite(swi, LOW) ;
 if(Commang == 'Y') {digitalWrite(volt1, LOW);  digitalWrite(volt2, LOW); }
 if(Commang == 'N') {digitalWrite(volt1, HIGH); digitalWrite(volt2, HIGH);}
 
 //Serial.flush();
}
