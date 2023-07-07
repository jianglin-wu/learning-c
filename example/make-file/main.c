#include <stdio.h>
#include "max.h"
#include "min.h"

// 头文件与源码分离
// 如何编译(确保安装有 make 工具)：
//     $ make -v # 查看是否安装 make，没安装如使用 sudo apt-get install make
//
//     $ make # 编译
//     $ ./main.out
//
// 具体配置请看 Makefile

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
