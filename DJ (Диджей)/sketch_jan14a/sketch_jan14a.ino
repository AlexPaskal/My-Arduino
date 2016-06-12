#define piezo 6

boolean oo = false;

void setup()
{
Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop()
{
  char a = Serial.read();
int x = analogRead(0);
  
  if(a == '+' || a == '=') oo = true;
  if(a == '-' || a == '_') oo = false;
  
if(oo == true)
{
 int reaL = map(x, 1023, 0, 500, 1000);
 tone(piezo, reaL); 
  delay(100);
} else noTone (piezo);
 
}
