#include <stdio.h>

int main()
{
    int i = 0;
    int *p = &i;

    printf("指针（地址）的值为：%p\n", p);
    printf("指针（sizeof）的值为：%lu\n", sizeof(p));
    printf("变量的值为：%d\n", i);
    return 0;
}
