int LedRed = 8;
boolean OORed = false;

int LedYel = 3;
boolean OOYel = false;

int LedGre = 2;
boolean OOGre = false;

void setup()
{
Serial.begin(9600);

pinMode(LedRed, OUTPUT);
pinMode(LedYel, OUTPUT);
pinMode(LedGre, OUTPUT);

digitalWrite(LedRed, LOW);
digitalWrite(LedYel, LOW);
digitalWrite(LedGre, LOW);
}

void loop()
{ 
 while (Serial.available() == 0) ;
 
 char ReaD = Serial.read();
//////////////////////////////////////////////////////////////////
if(ReaD == 'R') digitalWrite (LedRed, HIGH);
if(ReaD == 'r') digitalWrite (LedRed, LOW);

if(ReaD == 'Y') digitalWrite (LedYel, HIGH);
if(ReaD == 'y') digitalWrite (LedYel, LOW);

if(ReaD == 'G') digitalWrite (LedGre, HIGH);
if(ReaD == 'g') digitalWrite (LedGre, LOW);

if(ReaD == 'A')
 {digitalWrite (LedRed, HIGH);
  digitalWrite (LedYel, HIGH);
  digitalWrite (LedGre, HIGH);}
if(ReaD == 'a')
 {digitalWrite (LedRed, LOW);
  digitalWrite (LedYel, LOW);
  digitalWrite (LedGre, LOW);}
  
  else;


}

