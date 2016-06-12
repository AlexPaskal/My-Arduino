
int buttonPin = 2;
boolean currentButton = LOW;
boolean lastButton = LOW;
boolean debounce(int Pin, boolean last)
{
 boolean current = digitalRead(Pin);
    if(current != last)
      {
        delay(5);
        current = digitalRead(Pin);
      } 
  return(current);    
}
void setup()
{
 pinMode(buttonPin, INPUT);
 Serial.begin(9600);

}

void loop()
{
   


    Serial.print("012345");
    
// if( debounce(buttonPin, lastButton) == HIGH && lastButton == LOW )
// {
//   Serial.println("SSBX");
// }  lastButton = debounce(buttonPin, lastButton);
 
 //if(Serial.available() >0 && Serial.read() == 'Y') Serial.write('Y');
 
 delay(1000);
}
