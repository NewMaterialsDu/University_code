
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include"cir.h"
#include"point.h"

using namespace std;


//案例2：点和圆的关系  设置一个圆形类(cir)和点类，计算点(point)和圆的关系
//点到圆心的距离和半径比较
//两点距离的平方(因为根号开方在代码中不好写)：(x1-x2)^2 +(y1-y2)^2 
//半径的平方：m_r ^2


//通常一个class做一个文件夹
//class point {
//
//public:
//    //设置和获取xy
//    void setx(int x) {
//        m_x = x;
//    }
//    int getx() {
//        return m_x;
//    }
//
//    void sety(int y) {
//        m_y = y;
//    }
//    int gety() {
//        return m_y;
//    }
//
//private:
//    int m_x;
//    int m_y;
//
//
//};
//
//class cir {
//public:
//    //设置和获取半径圆心
//    void setr(int r) {
//        m_r = r;
//    }
//    int getr() {
//        return m_r;
//    }
//
//    void setcenter(point center) {
//        m_center = center;
//    }
//    point getcneter() {
//        return m_center;
//    }
//
//private:
//    int m_r;//半径
//
//    point m_center;//圆心
//
//};

void isincircle(point &d, cir &y) {
    //两点间距离平方
    int dis = (
        (y.getcneter().getx() - d.getx()) * (y.getcneter().getx() - d.getx())
        + (y.getcneter().gety() - d.gety()) * (y.getcneter().gety() - d.gety())
        );
    //半径平方
    int b = y.getr() * y.getr();
    //判断
    if (dis == b) {
        cout << "点在圆上！" << endl;
    }
    else if (dis > b) {
        cout << "点在圆外！" << endl;
    }
    else {
        cout << "点在圆内!" << endl;
    }


}

int main()
{

    //案例2：
    //创建圆
    cir q1;
    q1.setr(10);
    point center;
    center.setx(10);
    center.sety(0);
    q1.setcenter(center);


    //创建点
    point d1;
    d1.setx(10);
    d1.sety(9);

    isincircle(d1, q1);

    return 0;
}
