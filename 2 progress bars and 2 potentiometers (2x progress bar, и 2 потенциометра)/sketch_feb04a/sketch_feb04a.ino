int Pins[20]; //from R to L (like jews)
//int LPot = 1;
//int RPot = 0;

void setup()
{
  for(int i = 0; i < 20; i++) Pins[i] = i+22;
  for(int i = 0; i < 20; i++) pinMode(Pins[i], OUTPUT);
}

int RPotVal, LPotVal;
boolean LLeds[20], RLeds[20];

void loop()
{
  for(int i = 0; i < 20; i++) {LLeds[i] = false; RLeds[i] = false;}
  
  RPotVal = map(analogRead(A0), 0, 100, 0, 20);
  //LPotVal = map(analogRead(A8), 0, 1023, 20, 0);
  
  for(int i = 0; i < RPotVal; i++) RLeds[i] = true; 
  //for(int i = 20; i > LPotVal; i--) LLeds[i-1] = true;
  
  for(int i = 0; i <= 19; i++)
  {
    boolean IsLed = (RLeds[i] != LLeds[i]);
    digitalWrite(Pins[i], IsLed);
  }
  
  delay(10);
}
