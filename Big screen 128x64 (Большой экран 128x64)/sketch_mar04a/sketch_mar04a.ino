#include <U8glib.h>
U8GLIB_ST7920_128X64 u8g(3, 8, 7, U8G_PIN_NONE);

int x=9;

void setup()
{
 // u8g.setFont(u8g_font_gdb30);
 u8g.firstPage();  
  do {
u8g.setFont(u8g_font_6x12);
u8g.drawStr(0, 7, "Hello everybody!!!");
u8g.drawStr(10, 50, "http://nnm.me");
 // u8g.setColorIndex(1);
  } while( u8g.nextPage() ); 
}

void loop()
{
      /*        x=x+1;
   u8g.firstPage();  
  do {  
    u8g.setFont(u8g_font_6x12);
u8g.drawStr(0, 7, "Hello everybody!!!");
u8g.drawStr(10, 50, "http://nnm.me");
  u8g.setColorIndex(1);
    
 u8g.drawLine(10, 25, x, 25);
   } while( u8g.nextPage() ); 
   
  if(x==100) x=9; 
   
 delay(100);*/
}
