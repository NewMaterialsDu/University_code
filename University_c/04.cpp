#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main01() {
	//4.1
	//选择结构 单行if语句
	//int score = 0;
	//cout << "请输入一个分数：" << endl;
	//cin >> score;
	//cout << "您的成绩为：" << score << endl;
	//if (score >= 600) {
	//	cout << "恭喜您考上了一本大学！" << endl;
	//}
	//4.1多行if语句
	//多行if语句

	int score = 0;
	cout << "请输入一个分数：" << endl;
	cin >> score;
	cout << "您的成绩为：" << score << endl;
	if (score >= 600) {
		cout << "恭喜你考入一本大学！" << endl;
		if (score > 700) {
			cout << "恭喜你能上清华大学！" << endl;
		}
		else if (score>=650)
	{
			cout << "恭喜你能上北京大学！" << endl;
		}
		else
		{
			cout << "恭喜你能上人民大学！" << endl;
		}
	}
	else if (score>=500) {
		cout << "恭喜你考上公办大学！" << endl;
	
	}
	else {
		cout << "恭喜你考上大学！" << endl;
	}







	system("pause");
	return 0;
}