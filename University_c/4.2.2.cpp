#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main05() {
	//do...while语句

	int num = 0;
	do {
		cout << num << endl;
		num++;
	} while (num < 10);

	//先执行一次，在判断条件是否符合，符合则继续执行，直到不符合条件

	//4.2.3for循环语句

	//乘法口诀表

	for (int a = 1; a <= 9;a++) {
		for (int b = 1; b <= a;b++) {
			cout << b << "x" << a << " = " << a * b << "    ";
			
		}
		cout << endl;
	}
	//4.3
	//4.3.1

	//break跳出循环



	system("pause");
	return 0;
}
