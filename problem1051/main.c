// 结构体之成绩统计2
// https://www.dotcpp.com/oj/problem1051.html
#include <stdio.h>
#include <float.h>
// #include <inttypes.h>
 
int main()
{
   // printf("float 存储最大字节数 : %lu \n", sizeof(float));
   // printf("float 最小值: %E\n", FLT_MIN );
   // printf("float 最大值: %E\n", FLT_MAX );
   // printf("精度值: %d\n", FLT_DIG );

    float m=134.375;
    char *a=(char*)&m;

    printf("0x%p:%u\n",&a,*a);
    printf("0x%p:%u\n",&a+1,*(a+1) );
    printf("0x%p:%u\n",&a+2,*(a+2) );
    printf("0x%p:%u\n",&a+3,*(a+3) );
    printf("%f\n", m);
    printf("%u\n", m);

    // short int n=-123;
    // unsigned short int *p=(unsigned short int *)&n;

    // printf("%d\n",n);
    // printf("%d\n",*p);

   return 0;
}