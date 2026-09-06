#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;




int main() {
	//7指针
	//7.1指针的概念
	//可以通过指针间接访问内存
	//可以通过指针保存地址，指针就是一个地址





	//7.2指针变量的定义和使用
	int a = 10;
	//指针定义的语法：数据类型 * 指针变量名；
	int* p;
	//让指针记录变量a的地址
	p = &a;
	cout << "a 的地址为：" << &a << endl;
	cout << "p为：" << p << endl;

	//可以通过解引用的方式来找到指针指向的内存
	//指针前加 * 代表解引用，找到指针指向的内存中的数据
	//即*p = a = 10
	*p = 1000;
	cout << "a为：" << a << endl;
	cout << " *p为：" << *p << endl;


	//7.3指针所占用的内存空间
	//指针也是一种数据类型，那么占用的内存空间为多少呢？
	//在32位操作系统下：所有类型的指针占用空间都为4个字节
	//在64位操作系统下：所有类型的指针占用空间都为8个字节
	cout << "sizeof(int *) = " << sizeof(int*) << endl;
	cout << "sizeof(p) = " << sizeof(p) << endl;

	cout << "sizeof(float *) = " << sizeof(float*) << endl;
	cout << "sizeof(double *) = " << sizeof(double*) << endl;
	cout << "sizeof(char *) = " << sizeof(char*) << endl;


	//7.4空指针和野指针
	//指针变量指向内存中编号为0的空间为空指针
	//可以用来初始化指针变量
	//空指针指向的内存是不可以访问的

	int* x = NULL;
	//初始化指针变量

	//*x = 100;
	//0-255之间的内存编号是系统占用的，因此不可以访问

	//野指针：指针变量指向非法的内存空间
	//int* y = (int*)0x1200;
	//上述地址没有申请储存数据冒然访问会报错





	return 0;

}
