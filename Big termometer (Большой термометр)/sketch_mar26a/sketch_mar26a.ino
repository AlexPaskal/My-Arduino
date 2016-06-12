#include <U8glib.h>
U8GLIB_ST7920_128X64 u8g(3, 8, 7, U8G_PIN_NONE);
const int TSen = 0;
int tmp;


void setup()
{
  pinMode(TSen, INPUT);
}

void loop()
{
  
}
