#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>                                

int main() {
    char buf[10];
    // "0" 文件描述符，为标准输入流文件
    if (read(0, &buf, sizeof(buf)) == -1) {
        fprintf(stderr, "read error\n");
        return -1;
    }

    printf("read=%s", buf);
    return 0;
}
