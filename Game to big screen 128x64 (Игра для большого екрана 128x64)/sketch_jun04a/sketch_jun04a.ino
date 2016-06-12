#include <U8glib.h>
U8GLIB_ST7920_128X64 u8g(3, 8, 7, U8G_PIN_NONE);
int x = 0, y=32;
int X, Yu, Yd;
int count = 0;

void setup()
{

  do {
    u8g.setColorIndex(1);
    u8g.drawBox(0, 0, 128, 7);
    u8g.setColorIndex(0);
    u8g.setFont(u8g_font_04b_03);
    u8g.setPrintPos(2, 6);
    u8g.print("Count: "+String(count, DEC)+"/10   time: "+(String(millis() / 1000))+"."+String(millis() % 1000));
    u8g.setColorIndex(1);
u8g.drawPixel(x, y);
  } while( u8g.nextPage() );
  
  randomSeed(analogRead(2));
  Yu = random(8, 59);
}

void loop()
{
unsigned long a = millis()/1000;
  
  
if(analogRead(1) >= 1013) x--;
if(analogRead(1) <= 10) x++;

if(analogRead(0) >= 1013) y++;
if(analogRead(0) <= 10) y--;
 L:
Yd = Yu+4;
X = 126;
u8g.firstPage();  
  do {
    u8g.drawLine(X, 7, X, Yu);
    u8g.drawLine(X, 63, X, Yd);
u8g.drawPixel(x, y);
    u8g.setColorIndex(1);
    u8g.drawBox(0, 0, 128, 7);
    u8g.setColorIndex(0);
   u8g.setFont(u8g_font_04b_03);
    u8g.setPrintPos(2, 6);
    u8g.print("Count: "+String(count, DEC)+"/10   time: "+(String(millis() / 1000))+"."+String(millis() % 1000));
    u8g.setColorIndex(1);   
  } while( u8g.nextPage() );
  
if(x == X && y>Yu && y<Yd)
  {//////////////////////////////
    x=0;y=32;
    count ++;
  Yu = random(8, 59);
  goto L;
  } else{
    if(x == X){
u8g.firstPage();  
  do {
    u8g.setFont(u8g_font_6x12);
    u8g.drawStr(5,30, "! LLLOOOLLL ! ;-(");
//    u8g.drawStr(5, 42, "It was just");
//    u8g.drawStr(5, 54, String(count));
  } while( u8g.nextPage() );  
  while(true);
  }}
  
  if(count == 10 && (int)millis()<=180000)
  {
u8g.firstPage();  
  do {
    u8g.setFont(u8g_font_6x12);
    u8g.drawStr(5,30, "! THE BEST ! !-)");
  } while( u8g.nextPage() );  
  while(true);  
  }
  
  delay(2);
}
//
//void DrawSnake()
//{
//    u8g.firstPage();  
//  do {
//u8g.drawPixel(x, y);
//u8g.drawPixel(x1, y1);
//u8g.drawPixel(x2, y2);
//u8g.drawPixel(x3, y3);
//u8g.drawPixel(x4, y4);
//  } while( u8g.nextPage() );
//}
//
//void IF()
//{
//}
