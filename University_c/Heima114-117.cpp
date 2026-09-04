
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

//4.3.1成员变量和成员函数分开存储
//c++中类内的成员变量和成员函数分开储存
//只有非静态成员变量才属于类的对象上
//class person {
//
//    //非静态成员变量  属于类的对象上
//    int m_a;
//
//    //静态成员变量  不属于类的对象上
//    static int m_b;
//
//    //非静态成员函数  不属于类的对象上
//    void func() {
//
//    }
//
//    //静态成员函数  不属于类的对象上
//    static void func2() {
//
//    }
//
//};
//int person::m_b = 0;
//void test01() {
//    person p;
//    //c++编译器会给每个空对象也分配一个字节的空间，是为了区分空对象占用内存的位置，每个空对象也应该有一个独一无二的内存地址
//    cout << "size of p=" << sizeof(p) << endl;
//}
//
//void test02() {
//    person p2;
//    cout << "size of p2=" << sizeof(p2) << endl;
//
//}

//4.3.2this指针概念
//每一个非静态成员函数只会诞生一份函数实列，即多个同类对象会共用一块代码
//this指针指向被调用函数的成员函数所属对象
//this指针用途：当形参和成员变量同名时，可用this指针来区分
//在类的非静态成员函数中返回对象本身，可使用return *this
//class person {
//public:
//    person(int age) {
//        this->age = age;
//    }
//    //返回p2本体，要用引用方式返回
//    //如果不加&，那么就是返回一个值，成员变量调用时会创建副本，就不能做到改变p2本体
//    person& personaddage(person &p) {
//        this->age += p.age;
//        return *this;
//    }
//    int age;
//};
//void test01() {
//    person p1(18);
//    cout << "p1的年龄为：" << p1.age << endl;
//}
//void test02() {
//    person p1(10);
//    person p2(10);
//    //链式调用函数：返回p2，实现多次调用函数
//    p2.personaddage(p1).personaddage(p1).personaddage(p1);
//    cout << "p2的年龄为" << p2.age << endl;
//}

//4.3.3空指针访问成员函数
//class person {
//public:
//    void showclassnme() {
//        cout << "this is person class" << endl;
//    }
//    void showpersonage() {
//        //加上这个就不会报错
//        if (this == NULL) {
//            return;
//        }
//        //this是默认存在，不写也行
//        cout << "age = " << this->m_age<<endl;
//    }
//    int m_age;
//};
//void test01() {
//    person* p1 = NULL;
//    p1->showclassnme();
//    //报错是因为传入的是一个空指针
//    p1->showpersonage();
//}

//4.3.4const修饰成员函数
//加const后称为常函数或常对象
//常对象只能调用常函数，常函数内不可以修改成员属性
//成员属性声明时加关键字mutable后，在常函数中依然可以修改
class person {
public:
    //this指针的本质是指针常量  指针的指向是不可以修改的
    // const person * const this ;
    //在成员函数后面加const，修饰的是this指针，让指向的值也不可修改
    //变为常函数
    void showperson() const
    {
        //this->m_a = 100;
        //this = NULL;//this指针不可以修改指针的指向
        this->m_b = 100;
    }
    void func() {
        int m_a = 100;
    }
    int m_a;
    mutable int m_b;//特殊变量，即使在常函数中，也可以修改这个值
};
void test01() {
    person p1;
    p1.showperson();
}
void test02() {
    const person p2;//在对象前加const，变为常对象
    p2.m_b = 200;//这个是特殊值，在常对象中也可以修改
    //p2.m_a = 200;//报错
    //常对象只能调用常函数
    p2.showperson();
    //p2.func();//常对象不可以调用普通成员函数，因为普通成员函数可以修改属性(但是常对象是不可以修改的)
}


int main()
{
    //4.3.1
    //test01();
    //test02();

    //4.3.2
    //test01();
    //test02();

    //4.3.3
    test01();
    test02();

    system("pause");
    return 0;
}
