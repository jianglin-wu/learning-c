#include <stdio.h>

// 使用数值打印数组，以及使用 for 循环

int main()
{
  int ch;
  for ( ch = 65; ch <= 112; ch++ ) {
    printf("ASCII 值 = %d, 字符 = %c\n", ch, ch);
  }
  return 0;
}
