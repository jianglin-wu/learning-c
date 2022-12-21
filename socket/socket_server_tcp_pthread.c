#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 1027		//端口号
#define BACKLOG 50	//最大监听数


typedef struct {
    int value;
    pthread_t fd;
} DATA;

void *ThreadFun(void *arg)
{
	DATA* data = (DATA*)arg;
	int new_fd = data->value;
	int iRecvLen;
	char *buf = (char *) malloc(4096);
    printf("[New Thread] fd=%d\n", new_fd);
	//发送内容，参数分别是连接句柄，内容，大小，其他信息（设为0即可） 
	char *str = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Length: 5\r\nContent-Type: text/html\r\n\r\nok!\r\n";

    while (1) {
		iRecvLen = recv(new_fd, buf, 4096, 0);	
		if(0 >= iRecvLen)    //对端关闭连接 返回0
		{	
			printf("接收失败或者对端关闭连接！\n");
			close(new_fd);
			free(buf);
			break;
		}else{
			printf("[recv] %s\n", buf);
			send(new_fd, str, strlen(str), 0);
			printf("[send] %s\n", str);
			close(new_fd);
			free(buf);
			break;
		}
	}

    // while (1) {
	// 	iRecvLen = recv(new_fd, buf, 4096, 0);	
	// 	if(0 >= iRecvLen)    //对端关闭连接 返回0
	// 	{	
	// 		printf("接收失败或者对端关闭连接！\n");
	// 		close(new_fd);
	// 		free(buf);
	// 		break;
	// 	}else{
	// 		printf("buf: %s\n", buf);
	// 		send(new_fd, str, strlen(str), 0);
	// 	}
	// }
}

int main(void)
{  
	int iSocketFD = 0;  //socket句柄
	int i = 0;
	struct sockaddr_in stLocalAddr = {0}; //本地地址信息结构图，下面有具体的属性赋值
	struct sockaddr_in stRemoteAddr = {0}; //对方地址信息

	socklen_t socklen = 0;
	int len = 20;
	DATA **plist = malloc(sizeof(DATA) * len);
 
	iSocketFD = socket(AF_INET, SOCK_STREAM, 0); //建立socket
	if(0 > iSocketFD)
	{
		printf("创建socket失败！\n");
		return 0;
	}
 
	stLocalAddr.sin_family = AF_INET;  /*该属性表示接收本机或其他机器传输*/
	stLocalAddr.sin_port = htons(PORT); /*端口号*/
	stLocalAddr.sin_addr.s_addr = htonl(INADDR_ANY); /*IP，括号内容表示本机IP*/
	//绑定地址结构体和socket
	if(0 > bind(iSocketFD, (void *)&stLocalAddr, sizeof(stLocalAddr)))
	{
		printf("绑定失败！\n");
		return 0;
	}
 
	//开启监听 ，第二个参数是最大监听数
	if(0 > listen(iSocketFD, BACKLOG))
	{
		printf("监听失败！\n");
		return 0;
	}
 
	printf("iSocketFD: %d\n", iSocketFD);	
	//在这里阻塞知道接收到消息，参数分别是socket句柄，接收到的地址信息以及大小 
	while (1) {
		if (i >= len) {
            plist = (DATA **)realloc(plist, 5);
            len += 5;
            printf("len=%d\n", len);
        }
		plist[i] = (DATA *)malloc(sizeof(DATA));
		plist[i]->value = accept(iSocketFD, (void *)&stRemoteAddr, &socklen);
		if(0 > plist[i]->value)
		{
			printf("接收失败！\n");
			return 0;
		}else{
			printf("\n[accept] plist[i]->value: %d\n", plist[i]->value);
			int res = pthread_create(&plist[i]->fd, NULL, ThreadFun, &plist[i]->value);
			printf("pthread_create plist[i]->value=%d res=%d\n", plist[i]->value, res);
		}
		i++;
	}
}
