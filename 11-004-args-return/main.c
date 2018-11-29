#include <stdio.h>

//  接收启动参数长度，以及参数字符数组
//  返回状态码，返回值 0 为运行正常，返回值非 0 为运行错误

int main(int argv, char* argc[])
{
    int i;
    for (i=0; i<argv; i++) {
        printf("argc[%d]: %s\n", i, argc[i]);
    }
    return 0;
}
