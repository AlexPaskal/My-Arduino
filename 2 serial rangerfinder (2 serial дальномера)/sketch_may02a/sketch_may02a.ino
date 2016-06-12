#define Trig1 6
#define Echo1 7
#define Trig2 8
#define Echo2 9


void setup()
{
  Serial.begin(9600);
 pinMode(Trig1, OUTPUT);
  pinMode(Echo1, INPUT);
 pinMode(Trig2, OUTPUT);
  pinMode(Echo2, INPUT);
}

float impulseTime1=0; 
float distance_sm1=0; 
float impulseTime2=0; 
float distance_sm2=0; 

void loop()
{
   digitalWrite(Trig1, HIGH); 
  /* Подаем импульс на вход trig дальномера */
  delayMicroseconds(10); // равный 10 микросекундам 
  digitalWrite(Trig1, LOW); // Отключаем 
  impulseTime1=pulseIn(Echo1, HIGH); // Замеряем длину импульса 
  distance_sm1=impulseTime1/58; 
 //////////////////////////////////////////////////
   digitalWrite(Trig2, HIGH); 
  /* Подаем импульс на вход trig дальномера */
  delayMicroseconds(10); // равный 10 микросекундам 
  digitalWrite(Trig2, LOW); // Отключаем 
  impulseTime2=pulseIn(Echo2, HIGH); // Замеряем длину импульса 
  distance_sm2=impulseTime2/58; 
   Serial.write((byte)distance_sm1); 
 Serial.write((byte)distance_sm2); 
 delay(200);
}
