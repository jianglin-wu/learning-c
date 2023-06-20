#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <errno.h>

#define PORT 1025		//端口号
#define BACKLOG 5	//最大监听数

//发送内容，参数分别是连接句柄，内容，大小，其他信息（设为0即可） 
char *str = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Length: 5\r\nContent-Type: text/html\r\n\r\nok!\r\n";

int main()
{
	int iSocketFD = 0;  //socket句柄
	int iRecvLen = 0;   //接收成功后的返回值
	int new_fd = 0; 	//建立连接后的句柄
	char buf[4096] = {0}; //
	struct sockaddr_in stLocalAddr = {0}; //本地地址信息结构图，下面有具体的属性赋值
	struct sockaddr_in stRemoteAddr = {0}; //对方地址信息
	socklen_t socklen = 0;  	
 
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
	while(1) {
		//在这里阻塞知道接收到消息，参数分别是socket句柄，接收到的地址信息以及大小 
		new_fd = accept(iSocketFD, (void *)&stRemoteAddr, &socklen);
		if(0 > new_fd) {
			printf("接收失败！\n");
			continue;
		} else{
			printf("接收成功！\n");
		}
	
		printf("new_fd: %d\n", new_fd);	
		iRecvLen = recv(new_fd, buf, sizeof(buf), 0);	
		if(0 >= iRecvLen)    //对端关闭连接 返回0
		{	
			printf("接收失败或者对端关闭连接！\n");
		}else{
			printf("buf: %s\n", buf);
			send(new_fd, str, strlen(str), 0);
		}
		close(new_fd);
	}
	return 0;
}