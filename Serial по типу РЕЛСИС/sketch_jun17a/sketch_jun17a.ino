#define Relay_1 22
#define Relay_2 23
#define Relay_3 24
#define Relay_4 25

 boolean R1 = LOW;//volatile
 boolean R2 = LOW;//volatile
 boolean R3 = LOW;//volatile
 boolean R4 = LOW;//volatile

volatile boolean b_UPA_1 = false;
volatile boolean b_UPA_2 = false;
volatile boolean b_UPA_3 = false;
volatile boolean b_UPA_4 = false;

volatile unsigned long Norm1 = 0;
volatile unsigned long Norm2 = 0;
volatile unsigned long Norm3 = 0;
volatile unsigned long Norm4 = 0;

void setup()
{
  attachInterrupt(2, UPA_1, FALLING);
  attachInterrupt(3, UPA_2, FALLING);
  attachInterrupt(4, UPA_3, FALLING);
  attachInterrupt(5, UPA_4, FALLING);
  Serial.begin(9600);
  pinMode(Relay_1, OUTPUT); digitalWrite(Relay_1, !R1);
  pinMode(Relay_2, OUTPUT); digitalWrite(Relay_2, !R2);
  pinMode(Relay_3, OUTPUT); digitalWrite(Relay_3, !R3);
  pinMode(Relay_4, OUTPUT); digitalWrite(Relay_4, !R4);

}

void loop()
{
if(millis() % 100)
{
digitalWrite(Relay_1, !R1);
digitalWrite(Relay_2, !R2);
digitalWrite(Relay_3, !R3);
digitalWrite(Relay_4, !R4);
}
}

/////////////////////////////////////////////////////////////////////////////////////

char SerialRead[3];
byte SerialWrite[3];
  String StringWrite;
  
void serialEvent()
{
  if(Serial.available() >= 3){
Serial.readBytes(SerialRead, 3);
   if(SerialRead[0] == B00000001){//B00000001
      switch(SerialRead[1])
      {
        case 0x52://'R'
          SerialWrite[0] = B00000000;
          SerialWrite[1] = B00000000;
         if(R4) SerialWrite[2] = B00000001; else SerialWrite[2] = 0;
        if(R3) SerialWrite[2] += B00000010;
        if(R2) SerialWrite[2] += B00000100; 
        if(R1) SerialWrite[2] += B00001000;
        Serial.write(SerialWrite, 3);
          break;
        case 0x57://'W'
          StringWrite = String(SerialRead[2], BIN);
          while(StringWrite.length() < 4) StringWrite = "0"+StringWrite;
          if(StringWrite[0] == '1') R1 = HIGH; if(StringWrite[0] == '0') R1 = LOW;
          if(StringWrite[1] == '1') R2 = HIGH; if(StringWrite[1] == '0') R2 = LOW; 
          if(StringWrite[2] == '1') R3 = HIGH; if(StringWrite[2] == '0') R3 = LOW;
          if(StringWrite[3] == '1') R4 = HIGH; if(StringWrite[3] == '0') R4 = LOW;
          break;
      }
   }
}//S..available()
}

/////////////////////////////////////////////////////////////////////////////////////

void UPA_1()
{
  if(millis()>Norm1+30)
  {
   Norm1 = millis();
  R1 = !R1;
  }
}
void UPA_2()
{
  if(millis()>Norm2+30)
  {
   Norm2 = millis();
  R2 = !R2; 
  }
}
void UPA_3()
{
  if(millis()>Norm3+30)
  {
   Norm3 = millis();
  R3 = !R3; 
  }
}
void UPA_4()
{
    if(millis()>Norm4+30)
  {
   Norm4 = millis();
  R4 = !R4; 
  }
}
