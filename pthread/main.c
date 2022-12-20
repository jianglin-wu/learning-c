#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int value;
    pthread_t fd;
} DATA;

void *ThreadFun(void *arg)
{
	DATA* data = (DATA*)arg;
	int value = data->value;
	sleep(value);
    printf("ThreadFun value=%d done.\n", value);
}

int main(void)
{
	int i;
	int n;
    int res;
    DATA *plist[5];

    printf("请输入启动线程数：");
    scanf("%d", &n);


    for (i = 0; i < n; i++) {
        plist[i] = (DATA *)malloc(sizeof(DATA));
        plist[i]->value = i;
        res = pthread_create(&plist[i]->fd, NULL, ThreadFun, &plist[i]->value);
        printf("pthread_create i=%d, fd=%ld, res=%d\n", i, plist[i]->fd, res);
    }

    // 等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}
