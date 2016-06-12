const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;

void setup()
{
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(A) == HIGH) Serial.write(2);
  if(digitalRead(B) == HIGH) Serial.write(4);
  if(digitalRead(C) == HIGH) Serial.write(1);
  if(digitalRead(D) == HIGH) Serial.write(3);
  
  delay(100);
}
