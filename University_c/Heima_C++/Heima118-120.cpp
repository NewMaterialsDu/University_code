
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//4.4友元

//4.4.1全局函数做友元

//建筑物类
//class building {
//    //goodgay函数是building的friend，可以访问building的私有成员
//friend void goodgay(building* building);
//public:
//    building() {
//        m_sittingroom = "客厅";
//        m_bedroom = "卧室";
//    }
//public:
//    string m_sittingroom;//客厅
//private:
//    string m_bedroom;//卧室
//};
//
////全局函数
//void goodgay(building *building) {
//    cout << "好基友的全局函数正在访问：" << building->m_sittingroom << endl;
//    cout << "好基友的全局函数正在访问：" << building->m_bedroom << endl;
//}
//void test01() {
//    building building1;
//    goodgay(&building1);
//}

//4.4.2类做友元

//class building {
//friend class goodgay;
//public:
//    building();
//public:
//    string m_sittingroom;//客厅
//private:
//    string m_bedroom;//卧室
//
//};
////类外写成员函数
//building::building() {
//    m_sittingroom = "客厅";
//    m_bedroom = "卧室";
//}
//
//class goodgay {
//public:
//    goodgay();
//    //参观函数，访问building中的属性
//    void visit();
//    building* building1;
//};
//goodgay::goodgay() {
//    //创建建筑物对象
//    building1 = new building;
//}
//void goodgay::visit() {
//    //goodgay的public中的visit函数能访问building中的private属性
//    cout << "好基友正在访问：" << building1->m_sittingroom << endl;
//    cout << "好基友正在访问：" << building1->m_bedroom << endl;
//}
//
//void test01() {
//    goodgay gg;
//    gg.visit();
//}

//4.4.3成员函数做友元

//class building;
//
//class goodgay {
//public:
//    goodgay();
//    //让visit函数可以访问building的私有成员
//    void visit();
//    //visit2访问不到
//    void visit2();
//    building* building01;
//};
//
//class building {
//    friend void goodgay::visit();
//public:
//    building();
//public:
//    string m_sittingroom;//客厅
//private:
//    string m_bedroom;//卧室
//};
//
////类外实现成员函数
//building::building() {
//    m_sittingroom = "客厅";
//    m_bedroom = "卧室";
//}
//
//goodgay::goodgay() {
//    building01 = new building;
//}
//void goodgay::visit() {
//    cout << "visit函数正在访问：" << building01->m_sittingroom << endl;
//    cout << "visit函数正在访问：" << building01->m_bedroom << endl;
//}
//void goodgay::visit2() {
//    cout << "visit2函数正在访问：" << building01->m_sittingroom << endl;
////    cout << "visit2函数正在访问：" << building01->m_bedroom << endl;
//}
//
//
//void test01() {
//    goodgay gg;
//    gg.visit();
//    gg.visit2();
//}

int main()
{
    //4.4.1
     //test01();

     //4.4.2
     //test01();


     //4.4.3
     //test01();

    system("pause");
    return 0;
}
