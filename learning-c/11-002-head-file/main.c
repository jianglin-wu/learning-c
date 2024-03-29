#include <stdio.h>
#include "max.h"
#include "min.h"

// 头文件与源码分离
// 如何编译：
//     $ gcc -g -c ./max.c -o max.o
//     $ gcc -g -c ./min.c -o min.o
//     $ gcc -g ./max.o ./min.o ./main.c -o main.out
//     $ ./main.out
//
//     or
//
//     $ gcc -g ./max.c ./min.c ./main.c -o main.out
//     $ ./main.out
//
// 分离的好处：
//     将不常修改的文件抽离出来提前编译，修改后仅仅编译修改的文件，
//     当有成千上百个文件时可以大大提升编译效率。

int main(void)
{
    int a1 = 22;
    int a2 = 33;
    int maxNum = max(a1, a2);
    int minNum = min(a1, a2);
    printf("maxNum: %d\n", maxNum);
    printf("minNum: %d\n", minNum);
    return 0;
}
