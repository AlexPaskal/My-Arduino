int photo = 0;
int HC = 7;
int relay = 8;


void setup()
{
  pinMode(photo, INPUT);
  pinMode(HC, INPUT);
  pinMode(relay, OUTPUT);
  
  digitalWrite(relay, HIGH);
}

void loop()
{
 if(analogRead(photo) > 800 && digitalRead(HC) == HIGH)
  digitalWrite(relay, LOW); 
  else   digitalWrite(relay, HIGH);

delay(1000);
}
