#include <stdio.h>

// 输入多个数，计算总数与次数

int main()
{
    int flog = 1;
    int count = 0;
    int total = 0;

    while(flog == 1) {
        int input;
        scanf("%d", &input);
        if (input == 0) {
            flog = 0;
            break;
        }
        count++;
        total += input;
    }
    printf("%d,%d\n", total, count);
    return 0;
}
