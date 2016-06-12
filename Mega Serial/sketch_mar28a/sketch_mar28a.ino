byte LedBool[7];

  const int Led1 = 22;
  const int Led2 = 23;
  const int Led3 = 24;
  const int Led4 = 25;
  const int Led5 = 26;
  const int Led6 = 27;
  const int Led7 = 28;
  
void setup()
{
  Serial2.begin(9600);
    for(int i = 0; i<=6; i++)
    {LedBool[i] = 0;}
    
  for(int j = 22; j<=28; j++)
  {pinMode(j, OUTPUT);}  
}

void loop()
{
  while(Serial2.available()<7);
  
  for(int I = 0; I<=6; I++)
  {LedBool[I] = Serial2.read();}
 // Serial2.flush();
  
  if(LedBool[0] == 0) digitalWrite(Led1, LOW);
  else if(LedBool[0] == 1) digitalWrite(Led1, HIGH);
  if(LedBool[1] == 0) digitalWrite(Led2, LOW);
  else if(LedBool[1] == 1) digitalWrite(Led2, HIGH);
  if(LedBool[2] == 0) digitalWrite(Led3, LOW);
  else if(LedBool[2] == 1) digitalWrite(Led3, HIGH);
  if(LedBool[3] == 0) digitalWrite(Led4, LOW);
  else if(LedBool[3] == 1) digitalWrite(Led4, HIGH);
  if(LedBool[4] == 0) digitalWrite(Led5, LOW);
  else if(LedBool[4] == 1) digitalWrite(Led5, HIGH);
  if(LedBool[5] == 0) digitalWrite(Led6, LOW);
  else if(LedBool[5] == 1) digitalWrite(Led6, HIGH);
  if(LedBool[6] == 0) digitalWrite(Led7, LOW);
  else if(LedBool[6] == 1) digitalWrite(Led7, HIGH);

}
