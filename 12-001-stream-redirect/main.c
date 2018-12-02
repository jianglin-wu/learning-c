#include <stdio.h>

// 流与重定向
// 以下代码实现一个两数相除的功能，使用输入流获取数值，输出流返回结果，错误流提示用户。
// 编译与运行：
//     $ gcc main.c
//     $ ./a.out
//     < 输入数值 i
//     < 输入数值 j
//     > 返回结果
//
// 流的重定向：
//     $ ./a.out > out.txt  # 输出流到文件（覆盖）
//     $ ./a.out >> out.txt # 输出流到文件（追加）
//     $ ./a.out < in.txt   # 文件作为输入流
//
//     $ ./a.out 1> out.txt # 输出流到文件（覆盖）
//     $ ./a.out 2> err.txt # 错误流到文件（覆盖）
//
//     $ ./a.out < in.txt 1> out.txt 2> err.txt # 重定向所有流

int main()
{
    int i, j;
    printf("请输入一个数值 i：\n");
    scanf("%d", &i);
    printf("请输入一个数值 j：\n");
    scanf("%d", &j);

    if (j != 0) {
        printf("%d / %d = %d\n", i, j, i / j);
        return 0;
    }
    
    fprintf(stderr, "j 不能为 0！\n");
    return 1;
}
