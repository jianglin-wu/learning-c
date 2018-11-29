#include <stdio.h>
#include <limits.h>

// 使用 sizeof 查看大小
// 如下：使用 sizeof 获取数组长度
//     int a[] = {1, 2, 3, 4, 5};
//     int len = sizeof(a) / sizeof(a[0]);

int main()
{
  printf("long double 存储大小：%lu \n", sizeof(long double));
  return 0;  
}

