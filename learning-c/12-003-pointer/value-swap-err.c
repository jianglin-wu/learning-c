#include <stdio.h>

void swapValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 这是错误的做法！
// 交换两个变量的值，运行结果查看，变量的值并未发生改变。

int main()
{
    int a = 8, b = 6;
    printf("   init: a=%d, b=%d\n", a, b);
    swapValue(a, b);
    printf("changed: a=%d, b=%d\n", a, b);
    return 0;
}
