#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {

	//3.1 加减乘除
	printf("测试");

	//++,--,前置递增/递减，后置递增/递减
	//都是让变量递增或递减（无论放在前面还是后面）
	//区别：前置递增，先让变量+1 然后进行表达式运算
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << "a2 = " << a2 <<endl ;
	cout << "b2 = " << b2 <<endl;



	//后置变量，先进行表达式运算，后让变量+1
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << "a3 = " << a3 << endl;
	cout << "b3 = " << b3 << endl;

	//3.2赋值运算符
	//=  
	//+= a变成了原来的a加上一个数，下面同理，本质：a = a + 3
	//-=
	//*=
	///=
	//%=
	int a = 1;
	a += 3;
	cout << a << endl;

	//3.3比较运算符
	//==
	//！=
	//<
	//>
	//<=
	//>=
	int c = 10;
	int b = 20;
	cout << (c != b) << endl;
	cout << (c == b) << endl;
	//输出0为假，输出1为真

	//3.4  逻辑运算符 ：
	/*
	! 非 !a  如果a为假，则a为真；如果a为真，则a为假
	&& 与 a&&b 如果a和b都为真，则结果为真，否则为假
	|| 或 a||b 如果a和b有一个为真，则结果为真，二者都为假时，结果为假
	
	*/
	int a1 = 10;
	int b1 = 10;
	int c1 = 0;
	cout << !a1 << endl;
	cout << !!a1 << endl;
	cout << (a1 && b1) << endl;
	cout << (a1 && c1) << endl;
	cout << (a1 || c1) << endl;











	system("pause");

	return 0;

}