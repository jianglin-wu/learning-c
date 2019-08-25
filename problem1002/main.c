// 三个数最大值
// https://www.dotcpp.com/oj/problem1002.html

#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n", a > b && a > c ? a : b > c ? b : c);
	return 0;
}