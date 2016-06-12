 int Pins[3][6] = 
{
   {22, 23, 24, 25, 26, 27},  // 0 : GREEN
   {28, 29, 30, 31, 32, 33},  // 1 : RED
   {34, 35, 36, 37, 38, 39},  // 2 : YELLOW
}; 

int IsOnLed = 13;
int PhotoIn = 0;
int Sens = 40;

boolean IsON = false;
boolean IsCONF = false;
int mode = 0; // 0=ever, 1=light, 2=move
int anim = 0; // 


void setup()
{
  pinMode(IsOnLed, OUTPUT); digitalWrite(IsOnLed, LOW);
  
  pinMode(Sens, INPUT);
  for(int col = 0; col < 3; col++)
  { 
    for(int num = 0; num < 6; num++)
    {
      pinMode(Pins[col][num], OUTPUT);
    }
  }

  attachInterrupt(2, AKey, RISING);
  attachInterrupt(3, BKey, RISING);
  attachInterrupt(4, CKey, RISING);
  attachInterrupt(5, DKey, RISING);
}

void loop()
{
  ////////////////////ANIM_0////////////////////
  if (
       (IsON && anim == 0 && !IsCONF) &&
       (
         (mode == 0) ||
         (mode == 1 && analogRead(PhotoIn) < 512) ||
         (mode == 2 && digitalRead(Sens))
       )
     ) 
  {
  unsigned long mod1 = millis() % 7200;
  // 72 POS.
  if (               mod1<100  ) digitalWrite(Pins[0][0], HIGH);  
  if ( mod1>=100  && mod1<200  ) digitalWrite(Pins[1][0], HIGH);  
  if ( mod1>=200  && mod1<300  ) digitalWrite(Pins[2][0], HIGH);  
  if ( mod1>=300  && mod1<400  ) digitalWrite(Pins[0][1], HIGH);  
  if ( mod1>=400  && mod1<500  ) digitalWrite(Pins[1][1], HIGH);  
  if ( mod1>=500  && mod1<600  ) digitalWrite(Pins[2][1], HIGH);  
  if ( mod1>=600  && mod1<700  ) digitalWrite(Pins[0][2], HIGH);  
  if ( mod1>=700  && mod1<800  ) digitalWrite(Pins[1][2], HIGH);  
  if ( mod1>=800  && mod1<900  ) digitalWrite(Pins[2][2], HIGH);  
  if ( mod1>=900  && mod1<1000 ) digitalWrite(Pins[0][3], HIGH);  
  if ( mod1>=1000 && mod1<1100 ) digitalWrite(Pins[1][3], HIGH);  
  if ( mod1>=1100 && mod1<1200 ) digitalWrite(Pins[2][3], HIGH);  
  if ( mod1>=1200 && mod1<1300 ) digitalWrite(Pins[0][4], HIGH);  
  if ( mod1>=1300 && mod1<1400 ) digitalWrite(Pins[1][4], HIGH);  
  if ( mod1>=1400 && mod1<1500 ) digitalWrite(Pins[2][4], HIGH);  
  if ( mod1>=1500 && mod1<1600 ) digitalWrite(Pins[0][5], HIGH);  
  if ( mod1>=1600 && mod1<1700 ) digitalWrite(Pins[1][5], HIGH);  
  if ( mod1>=1700 && mod1<1800 ) digitalWrite(Pins[2][5], HIGH); // 
  if ( mod1>=1800 && mod1<1900 ) digitalWrite(Pins[0][0], LOW);  
  if ( mod1>=1900 && mod1<2000 ) digitalWrite(Pins[1][0], LOW);  
  if ( mod1>=2000 && mod1<2100 ) digitalWrite(Pins[2][0], LOW);  
  if ( mod1>=2100 && mod1<2200 ) digitalWrite(Pins[0][1], LOW);  
  if ( mod1>=2200 && mod1<2300 ) digitalWrite(Pins[1][1], LOW);  
  if ( mod1>=2300 && mod1<2400 ) digitalWrite(Pins[2][1], LOW);  
  if ( mod1>=2400 && mod1<2500 ) digitalWrite(Pins[0][2], LOW);  
  if ( mod1>=2500 && mod1<2600 ) digitalWrite(Pins[1][2], LOW);  
  if ( mod1>=2600 && mod1<2700 ) digitalWrite(Pins[2][2], LOW);  
  if ( mod1>=2700 && mod1<2800 ) digitalWrite(Pins[0][3], LOW);  
  if ( mod1>=2800 && mod1<2900 ) digitalWrite(Pins[1][3], LOW);  
  if ( mod1>=2900 && mod1<3000 ) digitalWrite(Pins[2][3], LOW);  
  if ( mod1>=3000 && mod1<3100 ) digitalWrite(Pins[0][4], LOW);  
  if ( mod1>=3100 && mod1<3200 ) digitalWrite(Pins[1][4], LOW);  
  if ( mod1>=3200 && mod1<3300 ) digitalWrite(Pins[2][4], LOW);  
  if ( mod1>=3300 && mod1<3400 ) digitalWrite(Pins[0][5], LOW);  
  if ( mod1>=3400 && mod1<3500 ) digitalWrite(Pins[1][5], LOW);  
  if ( mod1>=3500 && mod1<3600 ) digitalWrite(Pins[2][5], LOW); ////
  if ( mod1>=3600 && mod1<3700 ) digitalWrite(Pins[2][5], HIGH);  
  if ( mod1>=3700 && mod1<3800 ) digitalWrite(Pins[1][5], HIGH);  
  if ( mod1>=3800 && mod1<3900 ) digitalWrite(Pins[0][5], HIGH);  
  if ( mod1>=3900 && mod1<4000 ) digitalWrite(Pins[2][4], HIGH);  
  if ( mod1>=4000 && mod1<4100 ) digitalWrite(Pins[1][4], HIGH);  
  if ( mod1>=4100 && mod1<4200 ) digitalWrite(Pins[0][4], HIGH);  
  if ( mod1>=4200 && mod1<4300 ) digitalWrite(Pins[2][3], HIGH);  
  if ( mod1>=4300 && mod1<4400 ) digitalWrite(Pins[1][3], HIGH);  
  if ( mod1>=4400 && mod1<4500 ) digitalWrite(Pins[0][3], HIGH);  
  if ( mod1>=4500 && mod1<4600 ) digitalWrite(Pins[2][2], HIGH);  
  if ( mod1>=4600 && mod1<4700 ) digitalWrite(Pins[1][2], HIGH);  
  if ( mod1>=4700 && mod1<4800 ) digitalWrite(Pins[0][2], HIGH);  
  if ( mod1>=4800 && mod1<4900 ) digitalWrite(Pins[2][1], HIGH);  
  if ( mod1>=4900 && mod1<5000 ) digitalWrite(Pins[1][1], HIGH);  
  if ( mod1>=5000 && mod1<5100 ) digitalWrite(Pins[0][1], HIGH);  
  if ( mod1>=5100 && mod1<5200 ) digitalWrite(Pins[2][0], HIGH);  
  if ( mod1>=5200 && mod1<5300 ) digitalWrite(Pins[1][0], HIGH);  
  if ( mod1>=5300 && mod1<5400 ) digitalWrite(Pins[0][0], HIGH);// 
  if ( mod1>=5400 && mod1<5500 ) digitalWrite(Pins[2][5], LOW);  
  if ( mod1>=5500 && mod1<5600 ) digitalWrite(Pins[1][5], LOW);  
  if ( mod1>=5600 && mod1<5700 ) digitalWrite(Pins[0][5], LOW);  
  if ( mod1>=5700 && mod1<5800 ) digitalWrite(Pins[2][4], LOW);  
  if ( mod1>=5800 && mod1<5900 ) digitalWrite(Pins[1][4], LOW);  
  if ( mod1>=5900 && mod1<6000 ) digitalWrite(Pins[0][4], LOW);  
  if ( mod1>=6000 && mod1<6100 ) digitalWrite(Pins[2][3], LOW);  
  if ( mod1>=6100 && mod1<6200 ) digitalWrite(Pins[1][3], LOW);  
  if ( mod1>=6200 && mod1<6300 ) digitalWrite(Pins[0][3], LOW);  
  if ( mod1>=6300 && mod1<6400 ) digitalWrite(Pins[2][2], LOW);  
  if ( mod1>=6400 && mod1<6500 ) digitalWrite(Pins[1][2], LOW);  
  if ( mod1>=6500 && mod1<6600 ) digitalWrite(Pins[0][2], LOW);  
  if ( mod1>=6600 && mod1<6700 ) digitalWrite(Pins[2][1], LOW);  
  if ( mod1>=6700 && mod1<6800 ) digitalWrite(Pins[1][1], LOW);  
  if ( mod1>=6800 && mod1<6900 ) digitalWrite(Pins[0][1], LOW);  
  if ( mod1>=6900 && mod1<7000 ) digitalWrite(Pins[2][0], LOW);  
  if ( mod1>=7000 && mod1<7100 ) digitalWrite(Pins[1][0], LOW);  
  if ( mod1>=7100              ) digitalWrite(Pins[0][0], LOW);
  } 
  ////////////////////ANIM_1//////////////////// 
  else if (
       (IsON && anim == 1 && !IsCONF) &&
       (
         (mode == 0) ||
         (mode == 1 && analogRead(PhotoIn) < 512) ||
         (mode == 2 && digitalRead(Sens))
       )
     ) 
  {
  unsigned long mod2 = millis() % 3750;
  
  if (               mod2<50   ) { LedOff(); digitalWrite(Pins[0][0], HIGH); }  
  if ( mod2>=50   && mod2<100  ) digitalWrite(Pins[0][1], HIGH);
  if ( mod2>=100  && mod2<150  ) digitalWrite(Pins[0][2], HIGH);
  if ( mod2>=150  && mod2<200  ) digitalWrite(Pins[0][3], HIGH);
  if ( mod2>=200  && mod2<250  ) digitalWrite(Pins[0][4], HIGH);
  if ( mod2>=250  && mod2<300  ) digitalWrite(Pins[0][5], HIGH);
  // 1000
  if ( mod2>=1250 && mod2<1300 ) { LedOff(); digitalWrite(Pins[1][0], HIGH); }  
  if ( mod2>=1300 && mod2<1350 ) digitalWrite(Pins[1][1], HIGH);
  if ( mod2>=1350 && mod2<1400 ) digitalWrite(Pins[1][2], HIGH);
  if ( mod2>=1400 && mod2<1450 ) digitalWrite(Pins[1][3], HIGH);
  if ( mod2>=1450 && mod2<1500 ) digitalWrite(Pins[1][4], HIGH);
  if ( mod2>=1500 && mod2<1550 ) digitalWrite(Pins[1][5], HIGH);
  // 1000
  if ( mod2>=2500 && mod2<2550 ) { LedOff(); digitalWrite(Pins[2][0], HIGH); }  
  if ( mod2>=2550 && mod2<2600 ) digitalWrite(Pins[2][1], HIGH);
  if ( mod2>=2600 && mod2<2650 ) digitalWrite(Pins[2][2], HIGH);
  if ( mod2>=2650 && mod2<2700 ) digitalWrite(Pins[2][3], HIGH);
  if ( mod2>=2700 && mod2<2750 ) digitalWrite(Pins[2][4], HIGH);
  if ( mod2>=2750 && mod2<2800 ) digitalWrite(Pins[2][5], HIGH); 
  } 
  ////////////////////ANIM_2//////////////////// 
  else if (
       (IsON && anim == 2 && !IsCONF) &&
       (
         (mode == 0) ||
         (mode == 1 && analogRead(PhotoIn) < 512) ||
         (mode == 2 && digitalRead(Sens))
       )
     ) 
  {
  unsigned long mod3 = millis() % 8100;
    
  if (               mod3<500  ) OnColor(0, 5, 5);    // 500
  if ( mod3>=500  && mod3<600  ) LedOff();           // 100
  if ( mod3>=600  && mod3<1100 ) OnColor(1, 5, 5);    // 500
  if ( mod3>=1100 && mod3<1200 ) LedOff();           // 100
  if ( mod3>=1200 && mod3<1700 ) OnColor(2, 5, 5);    // 500
  if ( mod3>=1700 && mod3<2700 ) LedOff();           // 1000
  if ( mod3>=2700 && mod3<3200 ) OnColor(0, 1, 5);    // 500
  if ( mod3>=3200 && mod3<3300 ) LedOff();           // 100
  if ( mod3>=3300 && mod3<3800 ) OnColor(1, 2, 5);    // 500
  if ( mod3>=3800 && mod3<3900 ) LedOff();           // 100
  if ( mod3>=3900 && mod3<4400 ) OnColor(0, 2, 5);    // 500
  if ( mod3>=4400 && mod3<5400 ) LedOff();           // 1000
  if ( mod3>=5400 && mod3<5900 ) OnColor(0, 1, 2);    // 500
  if ( mod3>=5900 && mod3<6000 ) LedOff();           // 100
  if ( mod3>=6000 && mod3<6500 ) OnColor(0, 1, 2);    // 500
  if ( mod3>=6500 && mod3<6600 ) LedOff();           // 100
  if ( mod3>=6600 && mod3<7100 ) OnColor(0, 1, 2);    // 500
  if ( mod3>=7100              ) LedOff();           // 1000
  
  }
  ////////////////////CONF////////////////////
  else if ( IsCONF && IsON)
  {
  unsigned long modC = millis() % 1000;
  
  if ( modC<500 )
    {
      digitalWrite(Pins[0][5], HIGH);
      digitalWrite(Pins[1][5], HIGH);
      digitalWrite(Pins[2][5], HIGH);
    }
  if ( modC>=500 )
    {
      digitalWrite(Pins[0][5], LOW);
      digitalWrite(Pins[1][5], LOW);
      digitalWrite(Pins[2][5], LOW);
    }
  
  digitalWrite(Pins[0][1], LOW);
  digitalWrite(Pins[1][1], LOW);
  digitalWrite(Pins[2][1], LOW);
  digitalWrite(Pins[0][3], LOW);
  digitalWrite(Pins[1][3], LOW);
  digitalWrite(Pins[2][3], LOW);
  digitalWrite(Pins[0][4], LOW);
  digitalWrite(Pins[1][4], LOW);
  digitalWrite(Pins[2][4], LOW);
  
  switch(mode)
  {
    case 0:
      digitalWrite(Pins[0][0], HIGH);
      digitalWrite(Pins[1][0], LOW);
      digitalWrite(Pins[2][0], LOW); break;
    case 1:
      digitalWrite(Pins[0][0], LOW);
      digitalWrite(Pins[1][0], HIGH);
      digitalWrite(Pins[2][0], LOW); break;
    case 2:
      digitalWrite(Pins[0][0], LOW);
      digitalWrite(Pins[1][0], LOW);
      digitalWrite(Pins[2][0], HIGH); break;
  }  
  switch(anim)
  {
    case 0:
      digitalWrite(Pins[0][2], HIGH);
      digitalWrite(Pins[1][2], LOW);
      digitalWrite(Pins[2][2], LOW); break;
    case 1:
      digitalWrite(Pins[0][2], LOW);
      digitalWrite(Pins[1][2], HIGH);
      digitalWrite(Pins[2][2], LOW); break;
    case 2:
      digitalWrite(Pins[0][2], LOW);
      digitalWrite(Pins[1][2], LOW);
      digitalWrite(Pins[2][2], HIGH); break;
  }  
  }
  else LedOff();
}

void LedOff()
{
  for(int col = 0; col < 3; col++)
  { 
    for(int num = 0; num < 6; num++)
    {
      digitalWrite(Pins[col][num], LOW);
    }
  }
}
void OnColor(int col1, int col2, int col3)
{
  for(int col = 0; col < 3; col++)
  { 
    if ( col == col1 || col == col2 || col == col3 )
      for(int num = 0; num < 6; num++)
      {
        digitalWrite(Pins[col][num], HIGH);
      }
    else
    {
      for(int num = 0; num < 6; num++)
      {
        digitalWrite(Pins[col][num], LOW);
      }
    }
  }  
}

void AKey()
{
  IsON = !IsON;
  digitalWrite(IsOnLed, IsON);
  LedOff();
}
void BKey()
{
  if(IsON)
  {
    IsCONF = !IsCONF;
    LedOff();
  }
}
void CKey()
{
  if(IsCONF && IsON)
  {
    if(mode == 2) mode = 0;
    else mode++;
  }
}
void DKey()
{
  if(IsCONF && IsON)
  {
    if(anim == 2) anim = 0;
    else anim++;
  }
}
