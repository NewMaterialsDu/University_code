//数组特点：
//在初始化时，没有值的数组位置会默认为0
//放在一个连续的内存空间，数组中都是相同的数据类型
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	//5.2.2
	//一维数组名称的用途：
	//1.统计整个数组在内存中的长度
	
	int arr01[5] = { 10,20,30,40,50 };
	cout << "整个数组占用的内存空间：" << sizeof(arr01) << endl;
	cout << "每个元素占用的内存空间：" << sizeof(arr01[0]) << endl;
	//数组的元素的个数 = sizeof(arr01) / sizeof(arr01[0])
	cout <<"数组中元素的个数为：" << sizeof(arr01) / sizeof(arr01[0]) << endl;
	//2.获取数组在内存中的首地址
	cout << "数组的首地址为：" << (int)arr01 << endl;
	//默认为16进制，加上int后强制转换为10进制
	cout << "数组中第一个元素的地址为：" << (int)&arr01[0] << endl;
	cout << "第二个元素的地址为：" << (int)&arr01[1] << endl;
	//第一个元素和第二个相差4个字节，因为一个int为4字节
	//数组名是一个常量，不能赋值


	//数组最大值：
	int arr02[5] = { 300,350,200,400,250 };
	//认定一个最大值，依次访问每个元素比较所认定的最大值
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (arr02[i] > max) {
			max = arr02[i];
		}
	}
	cout << "最大值为：" << max << endl;

	//数组元素逆置：
	int arr03[5] = { 2,3,5,6,4 };
	int start = 0;//元素起始下标
	int end = sizeof(arr03) / sizeof(arr03[0]) - 1;//元素末尾下标 = 数组总数 - 1
	while (start < end) {
		int temp = arr03[start];
		arr03[start] = arr03[end];
		arr03[end] = temp;
		start++;
		end--;
		//把数组首位取出，首位和末位互换，下标往相反方向走
	}

	for (int i = 0; i < 5; i++) {
		cout << arr03[i] << endl;
	}












	system("pause");
	return 0;
}

