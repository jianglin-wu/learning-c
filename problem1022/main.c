// 筛选 N 以内的素数
// https://www.dotcpp.com/oj/problem1022.html

#include <stdio.h>
#include <stdbool.h>

// 是否是素数
bool isPrimeNum(int num)
{
	bool flag = false;
	for (int i = 2; i < num / 2 + 1; i++) {
		if (num % i == 0) {
			flag = true;
			break;
		}

	}
	return flag;
}


int main()
{
	int num = 0;
	int max = 9999;

	printf("请输入一个数：\n");
	scanf("%d", &num);

	if (num <= 0 || num >= max) {
		printf("输入 [%d] 值无效，请输入 1-%d 的值\n", num, max);
		return 1;
	}

	for (int i = 1; i < num; i++) {
		if (!isPrimeNum(i)) {
			printf("数值 %d 是素数\n", i);
		}
	}

	return 0;
}
