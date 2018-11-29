#include <stdio.h>

int main()
{
    fprintf(stdout, "请输入一个大于等于 0 的数值：\n");
    int num;
    fscanf(stdin, "%d", &num);
    if (num < 0) {
        fprintf(stderr, "输入错误，你输入的值是：%d\n", num);
        return 1;
    }
    fprintf(stdout, "输入的值是：%d\n", num);
    return 0;
}

