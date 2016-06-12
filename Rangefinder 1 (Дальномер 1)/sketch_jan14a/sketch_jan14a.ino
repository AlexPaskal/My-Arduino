#define Trig 7
#define Echo 8

void setup()
{
  Serial.begin(9600);
  
  pinMode(Trig, OUTPUT); //инициируем как выход 
  pinMode(Echo, INPUT); //инициируем как вход   
}

float impulseTime=0; 
float distance_sm=0; 

void loop()
{
  digitalWrite(Trig, HIGH); 
  /* Подаем импульс на вход trig дальномера */
  delayMicroseconds(10); // равный 10 микросекундам 
  digitalWrite(Trig, LOW); // Отключаем 
  impulseTime=pulseIn(Echo, HIGH); // Замеряем длину импульса 
  distance_sm=impulseTime/58; // Пересчитываем в сантиметры 
  Serial.print(distance_sm); // Выводим на порт   
  Serial.println(" cm");
  
  delay(500);
}
