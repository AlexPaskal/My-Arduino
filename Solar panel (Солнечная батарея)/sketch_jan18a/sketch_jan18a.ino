#include <Servo.h>
Servo ServoX;
Servo ServoY;

int InputX = 0;
int InputY = 1;

int Auto = 8;
int Manual = 7;
int Fixed = 11;

int AutoX = 44; //45-1
int AutoProv = 0;
int AutoY = 74; //(90-9)-1
boolean apM = true; //AM = true, PM = false;

void setup()
{
 ServoX.attach(10);
 ServoY.attach(9);
 
 pinMode(Auto, INPUT);
 pinMode(Manual, INPUT);
 pinMode(Fixed, INPUT);

 Serial.begin(9600);
 
 ServoX.write(90);
 ServoY.write(90);
}

void loop()
{
if(digitalRead(Manual) == HIGH){
  
int ReadX = analogRead(InputX);
int ReadY = analogRead(InputY);

int ResSX =  map(ReadX, 0, 1023, 40, 140);
int ResSY =  map(ReadY, 0, 1023, 40, 140);

if(digitalRead(Fixed) == LOW)
 {ServoX.write(ResSX);
  ServoY.write(ResSY);} } //Manual
  
  if(digitalRead(Auto) == HIGH)
{
  ServoX.write(44);
  ServoY.write(74);
  
    AutoX++;
    AutoProv++;
    if(AutoProv == 3){AutoProv = 0; if(apM == true)AutoY++;
                                    else           AutoY--;}
    
    if(AutoX == 90) apM = !apM;
    if(AutoX == 136){AutoX = 45;
                     AutoY = 80;
                     apM = true;
                   delay(2000);}
    
    ServoX.write(AutoX);
    ServoY.write(AutoY);
    
    delay(20);
} 
else if(digitalRead(Manual) == HIGH && digitalRead(Auto) == HIGH)  ;
else if(digitalRead(Manual) == LOW && digitalRead(Auto) == LOW)  ;
}

