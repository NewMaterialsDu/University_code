#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main() {

	//int num =0;
	//printf("请输入安全系数：");
	//scanf_s("%d", &num);
	//switch (num)
	//{
	//case 1:
	//	printf("系统正常！");
	//	break;

	//case 2:
	//	printf("系统警告！");
	//	break;

	//case 3:
	//	printf("系统危险！");
	//	break;

	//default:
	//	printf("危险操作，已自动停止！！！");
	//	break;
	//}

	int s = 0,y=2;
	for (int x = 1; x <= 100;x++) {
		s = x + y;
		cout << s << endl;
		x = y;
		y++;

	}


	return 0;
}