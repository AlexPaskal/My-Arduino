int termo = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int tmS = analogRead(termo);
  
 float volt = (tmS/1024.0)*5.0;
 float TMP = (volt - .5)*100;

 float Celsius = TMP;
 float Farengeit = ((Celsius * 9)/5) + 32;
 float Kelvin = (Celsius + 273.15);
  
  while (Serial.available() == 0) ;
  
  char priom = Serial.read();
       if (priom == 'C' || priom == 'c') 
     {Serial.print(Celsius); Serial.println(" *C");}
  else if (priom == 'F' || priom == 'f') 
     {Serial.print(Farengeit); Serial.println(" *F");}
  else if (priom == 'K' || priom == 'k') 
     {Serial.print(Kelvin); Serial.println(" *K");}
  else ;
}
