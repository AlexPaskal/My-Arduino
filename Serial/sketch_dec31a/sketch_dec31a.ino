int Led = 13;

void setup()
{
 Serial.begin(9600);
 pinMode(Led, OUTPUT);
}

void loop()
{
while(Serial.available() == 0);

char val = Serial.read();

if(val == '1') {
Serial.println("Led is ON");
digitalWrite(Led, HIGH);
}
else if(val == '0'){
  Serial.println("Led is OFF");
  digitalWrite(Led, LOW);
}
else {
Serial.println("Invalid");
}
Serial.flush();
}
