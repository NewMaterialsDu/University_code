#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#include<ctime>
//8.8.1结构体案例1：
//共有3个老师，每个老师带5名学生
//在老师结构体中，有老师姓名和一个存放5名学生的数组，学生结构体中有学生姓名和考试分数
//通过函数给老师和学生赋值，并打印出每个老师的姓名和他带的学生姓名和考试分数
struct Student {
	//char name[20];
	string Sname;
	//string是C++提供的字符串类，可以直接使用，不需要定义数组长度
	//char name[20]和string name的区别在于，前者是一个固定长度的字符数组，后者是一个动态长度的字符串类，可以根据需要自动调整长度
	int score;
};
struct Teacher {
	string Tname;
	Student students[5];
};
//给老师和学生赋值的函数声明和定义
void fuzhi(Teacher teachers[], int len) {
	string tname[5] = { "A","B","C","D","E" };
	//给老师
	for (int i = 0; i <= len - 1; i++) {
		teachers[i].Tname = "Teacher_";
		teachers[i].Tname += tname[i];
		//给学生
		for (int j = 0; j <= 4; j++) {
			teachers[i].students[j].Sname = "Student_";
			teachers[i].students[j].Sname += tname[j];
			teachers[i].students[j].score = rand() % 60 + 40;
			//rand() % 60 + 40的意思是生成一个40到99之间的随机整数
			
			
			//teachers[i].students[j].score = rand() % 101;
			//rand()函数是C++提供的一个随机数生成函数，返回一个0到RAND_MAX之间的整数，使得结果在0到100之间
		}
	}

}
//打印老师和学生信息的函数声明和定义
void printf(const Teacher teachers[],int len) {
	for (int i = 0; i <= len - 1; i++) {
		cout << "老师姓名：" << teachers[i].Tname << endl;
		for (int j = 0; j <= 4; j++) {
			cout << "\t学生姓名：" << teachers[i].students[j].Sname << "，考试分数：" << teachers[i].students[j].score << endl;
			//\t表示制表符，用于缩进输出
		}

	}
}

int main() {
	//随机数种子，srand()函数用于设置随机数生成的起始点，通常使用当前时间作为种子，以确保每次运行程序时生成不同的随机数序列
	srand((unsigned)time(NULL));


	//定义一个老师数组，包含3个老师
	Teacher teachers[3];
	//调用函数给老师和学生赋值
	int len = sizeof(teachers) / sizeof(teachers[0]);
	fuzhi(teachers, len);
	//调用函数打印老师和学生信息
	printf(teachers, len);


	return 0;

}
