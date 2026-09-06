
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
//3.1函数默认参数
//语法： 返回值类型 函数名（形参 = 默认值）{主体}
int func1(int a, int b = 20, int c = 30) {
    return a + b + c;
}

//int func2(int a, int b = 20, int c) {
//    return a + b + c;
//}
//注意：如果某个位置已经有了默认值，那么从这个位置从左到右都必须有默认值，所以func2函数调用会报错
//int func3(int a = 10, int b = 20);
//
//int func3(int a = 10, int b = 20) {
//    return a + b;
//}
//如果在函数的声明有了默认值，那在函数实现就不能有默认值，所以func3函数调用会报错
//即：函数声明和函数实现只能有一个默认值，不能同时有

// 3..2函数占位参数
//语法：返回值类型 函数名（数据类型）{ }
void func4(int a, int = 10) {
    cout << "hello ！" << endl;
}
//目前占位参数对现阶段没用，占位参数也可以有默认值

//3.3函数重载
//3.3.1函数重载概述
//可以让函数名相同，提高函数复用性
    //函数重载满足条件：同一作用域下  函数名相同  函数参数类型不同或者个数不同或者顺序不同
void func5() {
    cout << "func5的调用" << endl;
}
void func5(int a) {
    cout << "func5(int a)的调用" << endl;
}
void func5(double a) {
    cout << "func5(double a)的调用" << endl;
}
void func5(int a, double b) {
    cout << "func5(int a,double b)的调用" << endl;
}
void func5(double b, int a) {
    cout << "func5(double b,int a)的调用" << endl;
}

//int func5(double b, int a) {
//    cout << "func5(double b,int a)的调用" << endl;
//}
//注意：函数返回值不可以作为函数重载的条件，即：函数返回值类型不一样不能满足函数重载条件

//3.3.2函数重载的注意事项
//引用作为函数重载的条件
void func6(int& a) {//int &a = 10;不合法
    cout << "func6(int &a)的调用" << endl;
}
void func6(const int& a) {//const int &a = 10;合法
    cout << "func6(const int &a)的调用" << endl;
}
//属于类型不同

//函数重载碰到默认参数
void func7(int a) {
    cout << "调用func7（int a）" << endl;
}
void func7(int a, int b = 10) {
    cout << "调用func7（int a,int b =10）" << endl;
}



int main()
{
    //3.1函数默认参数
    cout << func1(10, 30) << endl;
    //传了就用传了的，没传就用默认值

//3.2函数占位参数
    func4(10, 20);
    //必须要有第二个，不然报错，因为有占位参数（除非有默认值）

    //3.3函数重载
//3.3.1函数重载概述
    func5();
    func5(10);
    func5(3.14);
    func5(5, 3.25);
    func5(3.15, 25);

    //3.3.2函数重载的注意事项
    int a = 10;
    func6(a);

    func6(10);

    //func7(10);//报错，不知道调用哪个


    return 0;
}
