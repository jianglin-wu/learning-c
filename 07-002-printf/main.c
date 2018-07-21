#include <stdio.h>

int main()
{
  int ch;
  for( ch = 65; ch <= 112; ch++ ) {
    printf("ASCII 值 = %d, 字符 = %c\n", ch, ch);
  }
  return 0;
}
