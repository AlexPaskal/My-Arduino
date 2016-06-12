int LedPin = 13;

void setup()
{
  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin, LOW);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() == 0) ;
char SR = Serial.read();
if(SR == 'H') {digitalWrite(LedPin, HIGH); 
    Serial.println('h');}
if(SR == 'L') {digitalWrite(LedPin, LOW);
    Serial.println('l');}
}
