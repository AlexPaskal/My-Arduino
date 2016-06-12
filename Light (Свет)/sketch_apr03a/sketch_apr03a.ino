const int MySens = 3;
   const unsigned long all = 30000000;     //300000000
const unsigned long signal = 15000000;    //180000000
                             16625248
const int relay = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(MySens, INPUT);
  pinMode(relay, OUTPUT);
 // digitalWrite(relay, HIGH);
}

void loop()
{
 //while(digitalRead(MySens) == LOW) {Serial.println("T"); delay(1000);}
 unsigned long LowTime = pulseIn(MySens, HIGH, all);
 Serial.println(LowTime);
 //delay(1000);
}
