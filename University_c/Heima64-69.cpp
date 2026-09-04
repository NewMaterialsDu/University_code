#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

//8.结构体(一种用户自定义的数据类型)
//struct在c++中可以省略（变量的时候可以省，定义时不能省）
//定义结构体语法：struct 结构体名 { };
struct Student {
	char name[20];
	int age;
};
//创建具体的学生（结构体变量）：struct 结构体名 变量名;
struct Student s1 = {
"张三", 20 
};
// s1为一个学生变量，s1.name为学生的名字，s1.age为学生的年龄

//8.2结构体数组定义：struct 结构体名 数组名[数组大小]={};
struct Student s[3] = {
	{ "张三", 20},
	{"李四", 21},
	{"王五", 22 }

};

//8.4结构体指针定义：struct 结构体名 *指针变量名;
//通过指针指向结构体变量：数据类型 指针->成员名;
struct Student* p = &s1;

//8.5结构体嵌套
struct teacher {
	char name[20];
	int age;
	struct Student stu; //结构体嵌套
};
//创建具体的老师（结构体变量）：
// 使用聚合初始化来初始化嵌套的结构体成员
teacher t = { "李老师", 40, { "张三", 20 } };

//8.6结构体作为函数参数
// 将学生结构体作为函数参数传递，并打印学生的所有信息
// 1.值传递	
void printStudent(Student s) {
	cout << "名字：" << s.name << " 年龄：" << s.age << endl;
}
//创建一个学生变量
Student s2 = { "赵六", 23 };

//2.地址传递
void printStudent2(Student* s) {
	cout << "名字：" << s->name << " 年龄：" << s->age << endl;
}

//8.7结构体中const的使用
//用const修饰结构体成员，表示该成员的值不能被修改
struct Student2 {
	char name[20];
	const int age; //年龄不能被修改
};

Student2 s3 = { "王五", 22 };
//将函数中的值传递改为地址传递，可以节省内存空间
void printStudent3(const Student2 *s) {
	//在结构体前加上const修饰，表示该结构体指针指向的内容不能被修改
	//s->age = 23; //编译错误，不能修改const成员
	cout << "名字：" << s->name << " 年龄：" << s->age << endl;
}
//const修饰的数据类型不能被修改，可以提高代码的安全性和可读性，防止意外修改数据。

int main() {
//结构体数组访问：
	for (int i = 0; i < 3; i++) {
		cout << "名字：" << s[i].name << " 年龄：" << s[i].age << endl;
	}
	//8.4
	cout << "名字：" << p->name << " 年龄：" << p->age << endl;
	//8.5
	cout << "老师名字：" << t.name << " 老师年龄：" << t.age << endl;
	cout << "学生名字：" << t.stu.name << " 学生年龄：" << t.stu.age << endl;

	//8.6    1. 值传递
	printStudent(s2);
	//8.6    2. 地址传递
	printStudent2(&s2);

	//8.7
	printStudent3(&s3);










	return 0;

}
