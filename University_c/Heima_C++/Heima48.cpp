#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	int arr[2][3] = { {1,2,3},{4,5,6} };
	//1.可以查看占用内存空间
	cout << sizeof(arr) << endl;
	//整形int占4个字节，二维数组有2行3列，所以占用4*2*3=24个字节
	cout << sizeof(arr[0]) << endl;
	//二维数组第一行占用4*3=12个字节
	cout << "二维数组的行数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组的列数为：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	//2.可以查看二维数组的首地址
	cout << "二维数组的首地址为：" << (int)arr << endl;
	//前面加上(int)是为了将地址转换成整数类型（十进制），以便更清晰地显示地址值
	cout << "二维数组第一行的首地址为：" << (int)arr[0] << endl;
	//二维数组第一行的首地址与二维数组的首地址相同，因为二维数组的元素是连续存储的
	cout << "二维数组第二行的首地址为：" << (int)arr[1] << endl;
	//二维数组第二行的首地址与二维数组的首地址相差12个字节，因为每行占用12个字节
	cout << "二维数组第一行第一个元素的地址为：" << (int)&arr[0][0] << endl;
	//二维数组第一行第一个元素的地址与二维数组的首地址相同，因为二维数组的元素是连续存储的

	return 0;

}
