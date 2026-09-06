
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//4.5运算符重载
//4.5.1加号运算符重载

//class person {
//public:
//    //1.成员函数重载+
//    //person operator+(person& p) {
//    //    person temp;
//    //    temp.m_a = this->m_a + p.m_a;
//    //    temp.m_b = this->m_b + p.m_b;
//    //    return temp;
//    //}
//    int m_a;
//    int m_b;
//};
//void test01() {
//    person p1;
//    p1.m_a = 10;
//    p1.m_b = 10;
//    person p2;
//    p2.m_a = 10;
//    p2.m_b = 10;
//    //调用成员函数重载实际上这里相当于person p3 = p1.operator+(p2)；
//    //调用全局函数重载相当于person p3 = operator+(p1,p2);
//    person p3 = p1 + p2;
//    cout << "p3.m_a=" << p3.m_a << endl;
//    cout << "p3.m_b=" << p3.m_b << endl;
//    //运算符重载也可以发生重载
//    person p4 = p1 + 100;
//    cout << "p4.m_a=" << p4.m_a << endl;
//    cout << "p4.m_b=" << p4.m_b << endl;
//}
////2.全局函数重载+
//person operator+(person& p1, person& p2) {
//    person temp;
//    temp.m_a = p1.m_a + p2.m_a;
//    temp.m_b = p1.m_b + p2.m_b;
//    return temp;
//}
////函数重载的版本
//person operator+(person& p1, int num) {
//    person temp;
//    temp.m_a = p1.m_a + num;
//    temp.m_b = p1.m_b + num;
//    return temp;
//}

//4.5.2左移运算符重载

//class person {
//    //全局函数配合友元就可以访问私有属性
//    friend  ostream& operator<<(ostream& out, person& p);
//public:
//    person( int a,int b){
//        m_a = a;
//        m_b = b;
//    }
//private:
//    //利用成员函数重载左移运算符
//    //void operator<<( cout ) { }
//    //简化得到p << cout
//    //无法实现，cout再左侧
//    //这里可以用cout做参数是因为cout本质是一个类对象
//    int m_a;
//    int m_b;
//};
////只能利用全局函数重载左移运算符
////这里点cout转到定义可以找到cout的类型（这里的名字用cout和其他都可以，因为传入的本质是起别名）
//ostream& operator<<(ostream &out , person &p) {  //本质operator << (cout , p) 简化cout <<  p
//    out << "m_a = " << p.m_a<<endl;
//    out << "m_b = " << p.m_b<<endl;
//    return out;
//}
//void test01() {
//    person p(10,20);
//    //p.m_a = 10;
//    //p.m_b = 10;
//    cout << p << "Hello Word!" << endl;
//}

//4.5.3递增运算符重载



//4.5.4数值运算符重载

//4.5.5关系运算符重载

//4.5.6函数调用运算符重载
int main()
{
    //4.5运算符重载
  //4.5.1加号运算符重载
    //test01();

  //4.5.2左移运算符重载
    test01();
  //4.5.3递增运算符重载

  //4.5.4数值运算符重载

  //4.5.5关系运算符重载

  //4.5.6函数调用运算符重载


    system("pause");
    return 0;
}
