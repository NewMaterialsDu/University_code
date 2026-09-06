#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
//6.2函数的定义，num1和num2为形参
//定义一个相加函数
int add(int num1, int num2) {
	int sum = num1 + num2;
	return sum;
}
//定义一个实现两个数字进行交换的函数
void swap(int num1,int num2) {
	/*cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;*/
	int temp = num1;
	num1 = num2;
	num2 = temp;

	/*cout << "交换后：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;*/

	return;
	//返回值不需要时可以不写return
}

//函数写在主函数后面时，可以提前声明函数的存在
int max(int num1, int num2);

int main() {
	//6.3函数的调用,ab为实参
	int a = 2;
	int b = 3;
	int c = add(a, b);
	cout << "相加的结果是：" << c << endl;


	//6.4值传递，如果函数不需要返回值，声明可以写void
	swap(a, b);
	//当我们做值传递时，函数的形参发生改变，并不会影响实参
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	//6.5函数的常见形式：无参无返，无参有返，有参无返，有参有返
	//6.6函数的声明，函数可以多次声明，但函数的定义只能有一次
	cout << max(a, b) << endl;
	//直接输出返回的数

	return 0;

}
//函数的定义
int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
	//比较大小，num1是否大于num2，是则返回num1，否则返回num2（三目运算）
}
