#include <stdio.h>
#include <assert.h>
#include "main.h"

typedef unsigned short int port_num;

int main()
{
    port_num port = getPort("请输入监听端口号：");
    printf("run%hu\n", port);
    return 0;
}

port_num getPort(char* inputTips)
{
    unsigned int port;
    printf("%s\n", inputTips);
    scanf("%d", &port);
    assert(port > 1023 && port < MAX_PORT);
    return (port_num) port;
}
