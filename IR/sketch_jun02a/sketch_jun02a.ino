#include <IR.h>

IR ir;
int code;

void setup()
{
  Serial.begin(9600);
ir.pinIR(9);  
ir.readEEPROM();
}

void loop()
{
  code = ir.readIR();
  if(code !=-1)
  Serial.println(code);
  delay(10);
}
