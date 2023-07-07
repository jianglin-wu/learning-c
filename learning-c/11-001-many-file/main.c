#include <stdio.h>
#include "./max.c"

// 多文件编译
// #include "./max.c" 将 max.c 中的文件复制到当前文件
// 这不是最好的做法，因为每次都会编译所有文件。
// 如何编译：
//     $ gcc ./main.c
//     $ ./a.out

int main(void){
    int a1 = 22;
    int a2 = 33;
    int maxNum = max(a1, a2);
    printf("maxNum: %d\n", maxNum);
    return 0;
}

