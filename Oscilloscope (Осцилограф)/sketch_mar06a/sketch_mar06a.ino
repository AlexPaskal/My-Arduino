#include <U8glib.h>
U8GLIB_ST7920_128X64 u8g(3, 8, 7, U8G_PIN_NONE);
int HistArr[128];
int PotPin = 1;
void setup()
{
  u8g.firstPage();  
  do {
  u8g.setColorIndex(1);   } while( u8g.nextPage() ); 
  pinMode(PotPin, INPUT);
  for (int i=0; i<128; i++){HistArr[i]=64;}
  u8g.firstPage(); do {  for (int i=0; i<128; i++){  
                             u8g.drawLine(i, HistArr[i], i, 0);
                            }} while( u8g.nextPage() ); 

}

void loop()
{
 int osc = map(analogRead(PotPin), 0, 1023, 63, 0); 
 for (int i=0; i<128; i++){HistArr[i]=HistArr[i+1];} 
 HistArr[127] = osc;
    u8g.firstPage(); do{ 
    for (int i=0; i<128; i++){
            u8g.drawLine(i, HistArr[i], i, 0);
                            }} while( u8g.nextPage() ); 
                            
                            
                          delay(200);  
}
