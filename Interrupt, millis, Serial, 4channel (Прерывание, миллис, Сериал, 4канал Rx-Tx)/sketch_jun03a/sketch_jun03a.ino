const int A = 3;
const int B = 4;
const int C = 5;
const int D = 6;
const int sens = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(sens, INPUT);
}

void loop()
{
  if(digitalRead(A) == HIGH) Serial.write(2);
  if(digitalRead(B) == HIGH) Serial.write(4);
  if(digitalRead(C) == HIGH) Serial.write(1);
  if(digitalRead(D) == HIGH) Serial.write(3);
  if(digitalRead(sens) == HIGH) Serial.write(5);
  delay(300);
}
