#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main03() {
	//三目运算符
	//表达式1？表达式2：表达式3
	//如果表达式1为真，执行表达式2，并返回表达式2的结果
	//如果表达式1为假，执行表达式3，并返回表达式3的结果
	int a = 10;
	int b = 20;
	int c = 0;

	c = a > b ? a : b;
	cout << "c = " << c << endl;

	//c++中三目运算符返回的是变量，可以继续赋值

	(a>b?a:b) = 100;
	cout << "a = " << a <<endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}