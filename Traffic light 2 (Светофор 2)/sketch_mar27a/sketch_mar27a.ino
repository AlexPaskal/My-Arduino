const int R1 = 12;
const int Y1 = 11;
const int G1 = 10;
const int R2 = 6;
const int Y2 = 5;
const int G2 = 4;

void setup()
{
 Serial.begin(9600);
 pinMode(R1, OUTPUT);
 pinMode(Y1, OUTPUT);
 pinMode(G1, OUTPUT);
 pinMode(R2, OUTPUT);
 pinMode(Y2, OUTPUT);
 pinMode(G2, OUTPUT);
 
}

void loop()
{
  while(Serial.available() == 0)  ;
  
 byte prn = Serial.read();
 Serial.flush();
 
 if(prn == 0) Led1(R1);
 if(prn == 1) Led1(Y1);
 if(prn == 2) Led1(G1);
 if(prn == 3) Led2(R2);
 if(prn == 4) Led2(Y2);
 if(prn == 5) Led2(G2);
}

void Led1(int Pin)
{
  digitalWrite(R1, LOW);
  digitalWrite(Y1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(Pin, HIGH);
}
void Led2(int Pin)
{
  digitalWrite(R2, LOW);
  digitalWrite(Y2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(Pin, HIGH);
}
