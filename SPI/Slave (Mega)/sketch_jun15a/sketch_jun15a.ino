#include <SPI.h>

int Byte;

void setup() {
  // put your setup code here, to run once:
SPI.begin();
pinMode(13, OUTPUT);\
digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
Byte = SPI.transfer();
if(Byte == 1) digitalWrite(13, LOW);

}
