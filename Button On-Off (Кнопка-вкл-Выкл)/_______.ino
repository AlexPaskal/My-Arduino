int kn = 13;    //button
int sd = 12;      //LCD
boolean key = false;

void setup() 
{
pinMode(kn, INPUT);
pinMode(sd, OUTPUT);
}

void loop()
{
 if (digitalRead(kn) == HIGH && key == true)
 {
 //digitalWrite(sd, HIGH);
 key = false ;
 } 
  if (digitalRead(kn) == HIGH && key == false)
 {
 key = true;
 } 
 
 if (key == true){
 digitalWrite(sd, HIGH);  
 } else {digitalWrite(sd, LOW); }
}
