//#include <EEPROM.h>
#include <IR.h>

IR ir;
int code;
byte level = 255;

#define motor 10

boolean IsOn = false;

void setup()
{
  ir.pinIR(9);  
  ir.readEEPROM();
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  code = ir.readIR();
  if(code != -1)
  {
    Serial.println(code);
    switch(code)
    {
       case -8087 : IsOn = !IsOn; if(IsOn) analogWrite(motor, level); else analogWrite(motor, 0); break; //        On/Off
       case -9137 : if(level < 200) level=200; else if(level < 255)level++; analogWrite(motor, level); break; //   /\
       case -8627 : if(level == 200) level=0; else if(level>200)level--; analogWrite(motor, level); break; //      \/
       case -8605 : level = 200; analogWrite(motor, level); break; //                                              |<<
       case -9117 : level = 255; analogWrite(motor, level); break;//                                               >>|
    }
  }
}
