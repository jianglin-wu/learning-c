// 阶乘求和
// https://www.dotcpp.com/oj/problem1014.html

#include <stdio.h>

int factorial(int n)
{
	int res = n;
	while(n > 1) {
      res *= n - 1;
      n--;
	}
	return res;
}


int main()
{
	int num = 0;
	int sum = 0;

	printf("请输入一个数：\n");
	scanf("%d", &num);
    
    if (num <= 0 || num >= 20) {
    	printf("输入 [%d] 值无效，请输入 0-20 的值\n", num);
    	return 1;
    }

    for (int i = 1; i <= num; i++) {
    	sum += factorial(i);
    }

    printf("计算结果为 %d\n", sum);
	return 0;
}
