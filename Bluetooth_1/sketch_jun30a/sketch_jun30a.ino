void setup()
{
  pinMode(13, OUTPUT);
  Serial3.begin(9600);
  digitalWrite(13, LOW);
}

void loop()
{
//  Serial3.write(10);
//  if(Serial3.available() >= 1)
//  {
//  byte c = Serial3.read();
//  if(c == 1) {digitalWrite(13, HIGH); Serial3.write(3);}
//  if(c == 0) {digitalWrite(13, LOW); Serial3.write(3);}
//  else Serial3.write(2);
//  }
//  
}

void serialEvent3()
{
  if(Serial3.available() >= 1)
  {
  byte c = Serial3.read();
  if(c == 1) {digitalWrite(13, HIGH); Serial3.write(3);}
  if(c == 0) {digitalWrite(13, LOW); Serial3.write(3);}
  }
}

