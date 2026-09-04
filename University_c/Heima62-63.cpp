#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void awsp(int *p1,int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	

}


int main() {
//7.7指针和函数
	
	int a = 10;
	int b = 20;
	awsp(&a,&b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	//地址传递，实参改变了

	//7.8冒泡排序的函数案例

	return 0;

}
