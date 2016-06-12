const int L1 = 22;
const int L2 = 23;
const int L3 = 24;


const int R1 = 25;
const int Y1 = 26;
const int G1 = 27;

const int R2 = 28;
const int Y2 = 29;
const int G2 = 30;

const int R3 = 31;
const int Y3 = 32;
const int G3 = 33;

const int R4 = 34;
const int Y4 = 35;
const int G4 = 36;

void setup()
{
  Serial1.begin(9600);
  for(int p = 22; p<=36; p++)
  {pinMode(p, OUTPUT);}
}

void loop()
{
  while(Serial1.available() == 0) /**/ ;
  
  char fC = Serial1.read();
  if(fC == 'A')   for(int i = 22; i<=36; i++)
                  {digitalWrite(p, LOW);}
  if(fC == 'S')  {char sC = Serial1.read();
                  char tC = Serial1.read();
  switch sC
  '1': ;
  '2': ;
  '3': ;
  '4': ;}
                
}

void Switch1(int Pin)
{
 digitalWrite(R1, LOW);
 digitalWrite(Y1, LOW);
 digitalWrite(G1, LOW);
 digitalWrite(Pin, HIGH);
}
void Switch2(int Pin)
{
 digitalWrite(R2, LOW);
 digitalWrite(Y2, LOW);
 digitalWrite(G2, LOW);
 digitalWrite(Pin, HIGH);  
}
void Switch3(int Pin)
{
 digitalWrite(R3, LOW);
 digitalWrite(Y3, LOW);
 digitalWrite(G3, LOW);
 digitalWrite(Pin, HIGH);
}
void Switch4(int Pin)
{
 digitalWrite(R4, LOW);
 digitalWrite(Y4, LOW);
 digitalWrite(G4, LOW);
 digitalWrite(Pin, HIGH);  
}
