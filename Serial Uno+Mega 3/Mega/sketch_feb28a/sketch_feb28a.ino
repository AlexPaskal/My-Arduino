 
void setup()
{
  Serial1.begin(9600);
}

void loop()
{
  while(Serial1.available() == 0) ;
  
  int i = Serial1.read();

    if(i == 2) {delay(1000);
                  Serial1.write(4);}

   
   Serial1.flush(); 
}

