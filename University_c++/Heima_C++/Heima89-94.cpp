
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//2.3
//交换函数
//1.值传递
void myswap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "swap01 a = " << a << endl;
    cout << "swap01 b = " << b << endl;

}

//2.地址传递
void myswap02(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;


}
//3.引用传递
void myswap03(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//2.4引用做函数的返回值
//1.不要返回局部变量的引用
int& test01() {
    int a = 10;//局部变量存放在四区中的栈区
    return a;
}

//2.函数的调用可以作为左值

int& test02() {
    static int a = 10;//静态变量，存放在全局区，在程序结束后系统释放
    return a;
}

//2.5发现是引用，转换为int* const tef = &a;
void func(int& tef) {
    tef = 100;//tef是引用，转换为tef = 100
}

//2.6常量引用

void show(const int& val) {
    //val = 1000;//加上const防止误操作
    cout << "val = " << endl;
}






int main()
{
    //2.1引用的基本使用
    //作用：给变量起别名
    //语法：数据类型 &别名 = 原名
    int a = 10;
    int& b = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //2.2引用的注意事项
    //1.引用必须要初始化
    //int& b; 错误的

    //2.引用一但初始化后，就可以更改了
    int c = 20;

    b = c;//赋值操作，而不是更改引用
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    //int& b = c  会报错：重新定义，多次初始化

    //2.3引用做函数的参数
    //利用引用的技术让形参修饰实参
    //可以简化指针修改实参
    int a1 = 10;
    int b1 = 20;

    //myswap01(a, b);//值传递，形参不会改变实参

    //myswap02(&a1, &b1); //地址传递，形参会修饰实参

    //myswap03(a1,b1);//引用传递，实参会修饰实参

    cout << "a1 = " << a1 << endl;
    cout << "b1 = " << b1 << endl;



    //2.4

    //int& ref = test01();
    //cout << ref << endl;//第一次是因为编译器做了保留
    //cout << ref << endl;//第二次因为内存已经释放
    //

    int& ref2 = test02();
    cout << ref2 << endl;
    cout << ref2 << endl;

    test02() = 1000;//如果函数的返回值是引用，这个函数的调用可以作为左值
    //相当于对a的操作，ref2相当于a的别名
    cout << ref2 << endl;
    cout << ref2 << endl;

    //2.5引用的本质
    int c1 = 10;
    //自动转换为 int* const tef = &c1;指针常量指向不可改，所以引用不可更改
    int& tef = c1;
    tef = 20;//内部发现tef是引用，自动转换为 tef = 20;

    cout << "c1:" << c1 << endl;
    cout << "tef2:" << tef << endl;

    func(a);

    //2.6常量引用
    //用来修饰形参，防止误操作

    //const int & ref3 = 10;//引用必须是一块合法的空间
    //加上const后，编译器将代码修改为 int temp = 10; const int & ref3 = temp;
    //ref3 = 20;//加上const之后变为只读，不可以修改

    int x = 100;
    show(x);

    cout << "x = " << x << endl;








    return 0;
}
