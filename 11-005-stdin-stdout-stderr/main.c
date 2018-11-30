#include <stdio.h>

// 输入输出以及错误流
// linux 一切皆文件，主要通过 stdin、stdout、stderr 来控制进程
// fprintf、fscanf 是 printf、scanf 的底层封装，可以设置写入流

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

