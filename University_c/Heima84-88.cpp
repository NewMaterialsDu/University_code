
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰全局变量、全局常量
const int c_g_a = 10;
const int c_g_b = 10;

//栈区的注意事项 ---不要返回局部变量的地址
//栈区的数据由编译器管理开辟和释放

int* func() {//形参也会存放在栈区
    int a = 10;//局部变量  存放在栈区，栈区的数据在函数执行完毕后自动释放
    return &a;//返回局部变量的地址
}

//利用new关键字，将数据开辟到堆区
int* func1() {
    //这个指针本质也是局部变量，放在栈上，指针保存的数据是放在堆区
    int* p1 = new int(10);
    return p1;
}

//1.new的基本语法
int* func2() {
    //在堆区创建整形数据
    //new的返回是该数据类型的指针
    int* p3 = new int(10);
    return p3;
}

void test1() {
    int* p3 = func2();
    cout << *p3 << endl;
    cout << *p3 << endl;
    cout << *p3 << endl;
    //堆区的数据由程序员管理开辟，由程序员释放
    //如果想释放，利用delete关键字
    delete p3;
    //cout << *p3 << endl; 内存已经释放，再次访问就是非法操作，会报错

}
//2.在堆区利用new开辟数组
void test2() {
    //创建10整形数据的数组
    int* arr = new int[10];//10代表数组有十个元素
    //返回的是一块连续地址的首地址
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 100;//给十个元素赋值，100到109
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
    //释放堆区数组要加[]才可以
    delete[] arr;
}

int main()
{

    //全局区

    //全局变量、静态变量、常量

    //创建普通局部变量
    int a = 10;
    int b = 10;

    cout << "局部变量a的地址为：" << (int)&a << endl;
    cout << "局部变量b的地址为：" << (int)&b << endl;

    cout << "全局变量g_a的地址为：" << (int)&g_a << endl;
    cout << "全局变量g_b的地址为：" << (int)&g_b << endl;

    //静态变量 普通变量前加static属于静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a的地址为：" << (int)&s_a << endl;
    cout << "静态变量s_b的地址为：" << (int)&s_b << endl;

    //常量
    //字符串常量
    cout << "字符串常量的地址为：" << (int)&"Hello World" << endl;

    //const修饰变量
    //const修饰全局变量、const修饰局部变量
    cout << "全局常量c_g_a的地址为：" << (int)&c_g_a << endl;
    cout << "全局常量c_g_b的地址为：" << (int)&c_g_b << endl;

    const int c_l_a = 10;
    const int c_l_b = 10;
    //c-const g-global l-local

    cout << "局部变量c_l_a的地址为：" << (int)&c_l_a << endl;
    cout << "局部变量c_l_b的地址为：" << (int)&c_l_b << endl;

    //接受func函数返回的值
    int* p = func();
    cout << *p << endl;//第一次可以打印正确的数字，是因为编译器做了保留
    cout << *p << endl;//第二次这个数据就不在保留

    //在堆区开辟数据
    int* p1 = func1();
    cout << *p1 << endl;

    test1();

    test2();


    return 0;
}
