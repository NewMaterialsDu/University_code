#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

#include"numh.h"
//双引号表示头文件是自定义的,上述表示引入头文件
//函数的声明
void swap(int a, int b);


int main() {

	//6.7函数的份文件编写
	//1.创建一个后缀为.h的头文件
	//2.创建一个后缀为.cpp的源文件
	//3.在头文件中写函数的声明
	//4.在源文件中写函数的定义
	int a = 10;
	int b = 20;
	swap(a, b);

	return 0;

}
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << endl;
	cout << "b = " << b <<endl;
}
