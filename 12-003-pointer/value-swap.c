#include <stdio.h>

void swapValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 正确的做法：
// 交换两个变量的值，给函数传入指针。

int main()
{
    int a = 8, b = 6;
    printf("   init: a=%d, b=%d\n", a, b);
    swapValue(&a, &b);
    printf("changed: a=%d, b=%d\n", a, b);
    return 0;
}
