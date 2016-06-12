  const int t1 = 2;
  const int t2 = 3;
  const int t3 = 4;
  const int t4 = 5;
  const int t5 = 6;
  const int t6 = 7;
  const int t7 = 8;
  const int t8 = 9;

void setup()
{
  pinMode(t1, INPUT);
  pinMode(t2, INPUT);
  pinMode(t3, INPUT);
  pinMode(t4, INPUT);
  pinMode(t5, INPUT);
  pinMode(t6, INPUT);
  pinMode(t7, INPUT);
  pinMode(t8, INPUT);
 Serial.begin(9600); 
}

void loop()
{
  if(digitalRead(t1) == HIGH) Serial.print(1);
  else                        Serial.print(0);
  if(digitalRead(t2) == HIGH) Serial.print(1);
  else                        Serial.print(0);
  if(digitalRead(t3) == HIGH) Serial.print(1);
  else                        Serial.print(0);
  if(digitalRead(t4) == HIGH) Serial.print(1);
  else                        Serial.print(0);
  if(digitalRead(t5) == HIGH) Serial.print(1);
  else                        Serial.print(0);
  if(digitalRead(t6) == HIGH) Serial.print(1);
  else                        Serial.print(0);
  if(digitalRead(t7) == HIGH) Serial.print(1);
  else                        Serial.print(0);
  if(digitalRead(t8) == HIGH) Serial.println(1);
  else                        Serial.println(0);
 
 delay(1000);
}
