
void setup()
{
Serial.begin(9600);  
}

void loop()
{
 while (Serial.available() == 0) ;
 
 char sR = Serial.read();
 if(sR == 'H') Serial.println('H');
 if(sR == 'L') Serial.println('L'); 
 if(sR == 'h') Serial.println("Recive HIGH.");
 if(sR == 'l') Serial.println("Recive LOW."); 
}
