#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main04() {
	//switch语句

	int score;
	cout << "请给电影打分（0-10的整数）：" << endl;
	cin >> score;
	cout << "你打的分数为：\n" << score << endl;
	switch (score) {
		//只能是整型或字符型，不能是区间
	case 10:
		cout << "您认为是经典电影" << endl;
		break;
		//退出当前分支
	case 9:
		cout << "您认为是经典电影" << endl;
		break;
	case 8:
		cout << "您认为好典电影" << endl;
		break;
	case 7:
		cout << "您认为是好电影" << endl;
		break;
	case 6:
		cout << "您认为是一般电影" << endl;
		break;
	case 5:
		cout << "您认为是一般电影" << endl;
		break;
	default:
		cout << "您认为是烂电影" << endl;
		break;
	}
	//4.2.1  while循环

	//猜数字游戏
	//rand()%100%100+1 水机生成0 + 1~99 + 1的数字


	system("pause");
	return 0;
}
