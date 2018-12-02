#include <stdio.h>

// 输入除数与被除数，计算平均值

int main()
{
    printf("输入除数与被除数，计算平均值（英文逗号分隔）\n");
    float total, count;
    scanf("%f,%f", &total, &count);
    float avg = total / count;
    printf("平均值为：%.2f\n", avg);
    return 0;
}
