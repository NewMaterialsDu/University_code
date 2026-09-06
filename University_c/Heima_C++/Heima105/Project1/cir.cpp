#include"cir.h"

//成员函数

//设置和获取半径圆心
void cir::setr(int r) {
    m_r = r;
}
int cir::getr() {
    return m_r;
}

void cir::setcenter(point center) {
    m_center = center;
}
point cir::getcneter() {
    return m_center;
}


