const int Red1 = 10;
const int Yellow1 = 9;
const int Green1 = 8;
const int Red2 = 7;
const int Yellow2 = 6;
const int Green2 = 5;

void setup()
{
       Serial.begin(9600);
  pinMode(Red1, OUTPUT);
  pinMode(Yellow1, OUTPUT);
  pinMode(Green1, OUTPUT);
  pinMode(Red2, OUTPUT);
  pinMode(Yellow2, OUTPUT);
  pinMode(Green2, OUTPUT);
  
}

void loop()
{
  while(Serial.available() < 2) ;
  
  char Read1 = Serial.read();
  char Read2 = Serial.read();
  
  if(Read1 == '1'){
   if(Read2 == '1') led1Proc(Red1);
   if(Read2 == '2') led1Proc(Yellow1);
   if(Read2 == '3') led1Proc(Green1);   
  }
  if(Read1 == '2'){
   if(Read2 == '1') led2Proc(Red2);
   if(Read2 == '2') led2Proc(Yellow2);
   if(Read2 == '3') led2Proc(Green2);   
  }  
  if(Read1 == '0'){
     digitalWrite(Red1, LOW); 
      digitalWrite(Yellow1, LOW);
       digitalWrite(Green1, LOW);  
        digitalWrite(Red2, LOW); 
         digitalWrite(Yellow2, LOW);
          digitalWrite(Green2, LOW);  
  }
}

void led1Proc(int Pin)
{
 digitalWrite(Red1, LOW); 
  digitalWrite(Yellow1, LOW);
   digitalWrite(Green1, LOW);
 digitalWrite(Pin, HIGH);
}
void led2Proc(int Pin)
{
 digitalWrite(Red2, LOW); 
  digitalWrite(Yellow2, LOW);
   digitalWrite(Green2, LOW);
 digitalWrite(Pin, HIGH);
}
