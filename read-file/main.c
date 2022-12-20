#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/tmp/a.txt", O_RDONLY);
    char buf[10];

    if (read(fd, &buf, sizeof(buf)) == -1) {
        fprintf(stderr, "read error\n");
        return -1;
    }

    printf("read=%s\n", buf);
    return 0;
}
