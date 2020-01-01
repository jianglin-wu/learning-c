#include <stdio.h>

typedef struct {
    char name[10];
    int age;
} Parson;

Parson* getInfo(Parson *info);

int main() {
    Parson info;
    getInfo(&info);
    printf("姓名是 %s，年龄是 %i \n", info.name, info.age);
    return 0;
}

Parson* getInfo(Parson *info)
{
    scanf("%s", info->name);
    scanf("%i", &info->age);
    return info;
}
