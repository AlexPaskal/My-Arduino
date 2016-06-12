byte Leds[12];


void setup()
{
 Serial2.begin(9600);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(13, OUTPUT);
}

void loop()
{
 while(Serial2.available()<12);
  Leds[0] = Serial2.read();
  Leds[1] = Serial2.read();
  Leds[2] = Serial2.read();
  Leds[3] = Serial2.read();
  Leds[4] = Serial2.read();
  Leds[5] = Serial2.read();
  Leds[6] = Serial2.read();
  Leds[7] = Serial2.read();
  Leds[8] = Serial2.read();
  Leds[9] = Serial2.read();
  Leds[10] = Serial2.read();
  Leds[11] = Serial2.read(); 
  
  analogWrite(2, Leds[0]);
  analogWrite(3, Leds[1]);
  analogWrite(4, Leds[2]);
  analogWrite(5, Leds[3]);
  analogWrite(6, Leds[4]);
  analogWrite(7, Leds[5]);
  analogWrite(8, Leds[6]);
  analogWrite(9, Leds[7]);
  analogWrite(10, Leds[8]);
  analogWrite(11, Leds[9]);
  analogWrite(12, Leds[10]);
  analogWrite(13, Leds[11]);
}
