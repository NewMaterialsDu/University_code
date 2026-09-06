#pragma once
#include<iostream>
using namespace std;
#include "point.h"
class cir {
public:
    //设置和获取半径圆心
    void setr(int r);
        
    int getr();
     

    void setcenter(point center);
    
    point getcneter();
     

private:
    int m_r;//半径

    point m_center;//圆心

};