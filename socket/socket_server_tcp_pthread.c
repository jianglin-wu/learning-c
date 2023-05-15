#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define PORT 1025		//端口号
#define BACKLOG 1	//最大监听数

//发送内容，参数分别是连接句柄，内容，大小，其他信息（设为0即可） 
char *str = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Length: 5\r\nContent-Type: text/html\r\n\r\nok!\r\n";

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

	do {
		iRecvLen = recv(new_fd, buf, 4096, 0);	
		if(0 >= iRecvLen) {	
			//对端关闭连接 返回0
			printf("接收失败或者对端关闭连接！\n");
			break;
		} else {
			printf("[recv] %s\n", buf);
			send(new_fd, str, strlen(str), 0);
			printf("[send] %s\n", str);
		}
    // 此处 while 为 true 表示保持 TCP 连接，为 false 表示响应数据后立即断开连接
	} while(0);

	close(new_fd);
	free(buf);
	free(data);
}

int main(void)
{  
	int iSocketFD = 0;  //socket句柄
	socklen_t socklen = 0;
	struct sockaddr_in stLocalAddr = {0}; //本地地址信息结构图，下面有具体的属性赋值
	struct sockaddr_in stRemoteAddr = {0}; //对方地址信息

	iSocketFD = socket(AF_INET, SOCK_STREAM, 0); //建立socket
	if(0 > iSocketFD)
	{
		fprintf(stderr, "[创建 Socket 失败] [errno=%d]: %s\n", errno, strerror(errno));
		return 1;
	}
 
	stLocalAddr.sin_family = AF_INET;  /*该属性表示接收本机或其他机器传输*/
	stLocalAddr.sin_port = htons(PORT); /*端口号*/
	stLocalAddr.sin_addr.s_addr = htonl(INADDR_ANY); /*IP，括号内容表示本机IP*/
	//绑定地址结构体和socket
	if(0 > bind(iSocketFD, (void *)&stLocalAddr, sizeof(stLocalAddr)))
	{
		fprintf(stderr, "[绑定失败] [errno=%d]: %s\n", errno, strerror(errno));
		return 1;
	}
 
	//开启监听 ，第二个参数是最大监听数
	if(0 > listen(iSocketFD, BACKLOG))
	{
		fprintf(stderr, "[监听失败] [errno=%d]: %s\n", errno, strerror(errno));
		return 1;
	}
 
	printf("iSocketFD: %d\n", iSocketFD);	
	//在这里阻塞知道接收到消息，参数分别是socket句柄，接收到的地址信息以及大小 
	while (1) {
		DATA *data = (DATA *)malloc(sizeof(DATA));
		data->value = accept(iSocketFD, (void *)&stRemoteAddr, &socklen);
		if(0 > data->value)
		{
			printf("接收失败！\n");
			return 0;
		}else {
			printf("\n[accept] data->value: %d\n", data->value);
			int res = pthread_create(&data->fd, NULL, ThreadFun, &data->value);
			printf("pthread_create data->value=%d res=%d\n", data->value, res);
		}
	}
}
