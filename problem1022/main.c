// 筛选 N 以内的素数
// https://www.dotcpp.com/oj/problem1022.html

#include <stdio.h>

int isPrimeNum(int num)
{
	int i = 2;
	int v;
	int flag = 0;
	while(i < num) {
		v = num % i;
		if (v == 0) {
			flag = 1;
			break;
		}
		i++;
	}
	return flag;
}

int main()
{
	int num = 0;

	printf("请输入一个数：\n");
	scanf("%d", &num);
    
    if (num <= 0 || num >= 200) {
    	printf("输入 [%d] 值无效，请输入 0-20 的值\n", num);
    	return 1;
    }

    int values[num];
    for (int i = 1; i < num; i++) {
    	int res = isPrimeNum(i);

    	if (res == 0) {
		    printf("数值 %d 是素数\n", i);
    	}
    }

	return 0;
}
