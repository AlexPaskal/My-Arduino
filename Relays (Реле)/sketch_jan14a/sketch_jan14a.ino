
void setup()
{
Serial.begin(9600);
pinMode(2, OUTPUT);
digitalWrite(2, HIGH);
}

void loop()
{
  while(Serial.available() == 0)  ;
  
  char symb = Serial.read();
 if(symb == '+') digitalWrite(2, LOW);
 if(symb == '-') digitalWrite(2, HIGH); 
}

