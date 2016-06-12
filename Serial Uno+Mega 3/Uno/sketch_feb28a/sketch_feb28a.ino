 int LedPin = 8;
void setup()
{
 Serial.begin(9600); 
 

 pinMode(LedPin, OUTPUT);
 digitalWrite(LedPin, LOW);
}


void loop()
{
Serial.write(2);

while(Serial.available() == 0);
int i = Serial.read();

if(i == 4) {
digitalWrite(LedPin, HIGH);
delay(1000);
digitalWrite(LedPin, LOW);
}
Serial.flush();
}
