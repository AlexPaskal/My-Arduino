int sO = 3;
int t = 7;    //vremya zaderzki. iznachalno-10;
boolean ppS = true;
boolean pS = true; //true-79,  false-169  
#include <Servo.h>
Servo myS;

void setup()
{
  pinMode(8, INPUT);
  
  myS.attach(3);
  myS.write(169);
}

void loop()
{
if(digitalRead(8) == HIGH){
  if (ppS == true){ //dlya togo, chtob ne bilo "kachel".
 if(pS == false){   //proverka polozenia
 for(int i = 79; i<=169; i++){
  myS.write(i); 
  delay(t);
 }
  pS = true;
  ppS = false; 
 
 } else{ //proverka polozenia
  for(int i = 169; i>=79; i--){ 
  myS.write(i);
  delay(t);
  }
  pS = false;
  ppS = false;  
 }                     //proverka polozenia
}//dlya togo, chtob ne bilo "kachel".
} else ppS = true;  //dlya togo, chtob ne bilo "kachel".
}//void loop
