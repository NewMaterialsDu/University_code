#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
//8.8.2结构体案例2：
//创建一个英雄结构体数组，包含姓名、年龄、性别，
//通过冒泡排序对英雄进行排序，按照年龄进行升序，最后输出排序后的结果

//定义一个英雄结构体
struct Hero {
	string name;
	int age;
	
};

Hero heroes[5] = {
	{"张三", 25},
	{"李四", 30},
	{"王五", 20},
	{"赵六", 28},
	{"钱七", 22}
};
//冒泡排序函数
void sheng(Hero heroes[],int len) {
	for (int i = 0; i <= len - 1; i++){
		for (int j = 0; j <= len - 2 - i; j++) {
			if (heroes[j].age > heroes[j + 1].age) {
				//if条件里面不能再写数据类型，因为在函数定义的时候已经定义了数据类型
				Hero temp = heroes[j];
				heroes[j] = heroes[j + 1];
				heroes[j + 1] = temp;
			}
		}

	}
	//输出排序后的结果
	for (int i = 0; i < len; i++) {
		cout << "姓名：" << heroes[i].name << "，年龄：" << heroes[i].age << endl;
	}
	
}

int main() {
	int len = sizeof(heroes) / sizeof(heroes[0]);
	//调用冒泡排序函数
	sheng(heroes, len);















	return 0;

}
