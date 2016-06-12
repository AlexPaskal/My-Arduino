
void setup()
{
 Serial.begin(9600); 
}

void loop()
{
  while (Serial.available() == 0) ;
  
  
  char sr = Serial.read();
  if(sr == 'B') Serial.write('X');
  else {sr=sr-32; Serial.write(sr);}  
}
