#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//非递归计算1-n
int fun01(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

//递归方式
int fun02(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return fun02(n - 1) + n;
	}
}

//求斐波那契数列第n项的值-非递归方式
int fibonacci01(int n) {
	int lact1 = 1;
	int lact2 = 1;
	int result = 0;
	for (int i = 3; i <= n; i++) {
		result = lact1 + lact2;
		lact2 = lact1;
		lact1 = result;
	}
	return result;
}

//递归方式
int fibonacci02(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return fibonacci02(n - 1) + fibonacci02(n - 2);
	}
}


int main() {
	printf("%d\n", fun01(100));
	printf("%d\n", fun02(3));






	return 0;
}