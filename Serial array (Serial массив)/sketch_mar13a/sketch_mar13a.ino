
void setup()
{
Serial.begin(9600);  
}

void loop()
{
  while(Serial.available() < 3) ;
  
  byte Bt1 = Serial.read();
  byte Bt2 = Serial.read();
  byte Bt3 = Serial.read(); 
 
   Serial.flush();
   
 char Ch1 = Bt1;
 char Ch2 = Bt2;
 char Ch3 = Bt3; 
 
 Serial.print(Ch1);
 Serial.print(Ch2);
 Serial.println(Ch3); 
 

}
