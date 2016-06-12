#include <SPI.h>

//const int ss = 10;
byte value = 0;

void setup() {
  // put your setup code here, to run once:
SPI.begin();

pinMode(SS, OUTPUT);
digitalWrite(SS, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() == 500){
digitalWrite(SS, LOW);
value = 1;
SPI.transfer(value);
digitalWrite(SS, HIGH);
}
}
