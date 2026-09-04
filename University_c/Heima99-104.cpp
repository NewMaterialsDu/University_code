
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>


using namespace std;

//4类和对象
    //4.1封装
    // 4.1.1
//设置一个圆类，求圆的周长
//圆的周长公式 ： 2 * PI * 半径

//圆周率
const double PI = 3.1415926;

//设计一个类
class yuan {
    //访问权限
public://公共权限
    //属性
    //半径
    int r;

    //行为（通常是一个函数）
    //获取圆的周长
    double calculate() {
        return 2 * PI * r;
    }


};


//设置一个学生类，属性有姓名和学号
//可以给姓名和学号赋值，可以显示学生的姓名和学号

//设置学生类

class student {
public://公共权限

    //类中的属性和行为统一称成员
    //属性 成员属性  成员变量
    //行为  成员函数 成员方法


    //属性
    string m_name;//学号
    int m_id;//姓名

    //行为
    //显示学生的姓名和学号
    void showstudent() {
        cout << "姓名：" << m_name << "学号：" << m_id << endl;
    }

    //给姓名赋值
    void setname(string name) {
        m_name = name;
    }

    //给学好赋值
    void setid(int id) {
        m_id = id;
    }

};

//访问权限有三种
// 公共权限 public      成员在类内可以访问  类外可以访问
//保护权限 protected    成员类内可以访问    类外不可以访问  儿子可以访问父亲中保护的内容
//私有权限 private      成员类内可以访问    类外不可以访问  儿子不可以访问父亲中的私有内容

class person {
public:
    //公共权限
    string a_name;


protected:
    //保护权限
    string a_car;

private:
    //私有权限
    string a_password;

public:
    void func01(string name, string car, int pass) {
        a_name = "张三";
        a_car = "同垃圾";
        a_password = "123456";

        a_name = name;
        a_car = car;
        a_password = pass;

    }

};

//4.1.2
//struct默认权限为公共
//class默认权限为私有

class b1 {
    int a;
};

struct b2 {
    int a;
};

//4.1.3
//成员属性设置为私有
//1.可以自己控制读取权限
//2.对于写可以检测数据的有效性
class pson {
public:
    //设置姓名
    void setname(string name) {
        a_name = name;
    }
    //获取姓名
    string ahowname() {

        return a_name;
    }
    //获取年龄
    int getage() {
        return a_age;
    }

    //设置偶像
    void setido(string ido) {
        a_ido = ido;
    }


private:
    string a_name;//姓名 可读可写
    int a_age = 18;//年龄 只读(此处设置默认年龄为18)
    string a_ido;//偶像 只写
};
//通过设置函数来控制读写权限

//案例1：设置立方体类  求出立方体类的面积和体积 分别用全局函数和成员函数判断两个立方体是否相等
class cube {
public:

    //行为
    //设置获取长宽高
    void setl(int l) {
        m_l = l;
    }

    int getl() {
        return m_l;
    }

    void setw(int w) {
        m_w = w;
    }

    int getw() {
        return m_w;
    }

    void seth(int h) {
        m_h = h;
    }

    int geth() {
        return m_h;
    }



    //获取面积和体积
    int calculates() {
        return 2 * m_l * m_w + 2 * m_l * m_h + 2 * m_h * m_w;
    }

    int calculatev() {
        return m_l * m_w * m_h;
    }

    //利用成员函数判断立方体是否相等
    bool issamebyclass(cube& z2) {
        if (getl() == z2.getl() && getw() == z2.getw() && geth() == z2.geth()) {
            return true;
        }
        return false;
    }
private:
    //属性
    int m_l;
    int m_w;
    int m_h;


};

//利用全局函数判断两个立方体是否相等
bool issame(cube& z1, cube& z2) {
    if (z1.getl() == z2.getl() && z1.getw() == z2.getw() && z1.geth() == z2.geth()) {
        return true;
    }
    return false;
}


int main()
{
    //4类和对象
     //4.1封装
     //4.1.1
     //通过圆类创建具体的圆（对象）
    yuan c1;
    //给圆对象的属性赋值
    c1.r = 10;
    cout << "圆c1的周长为：" << c1.calculate() << endl;



    //创建一个具体的学生
    student s1;
    //s1.m_name = "张三";
    s1.setname("张三");
    //s1.m_id = 1;
    s1.setid(1);
    //显示学生的姓名和学号
    s1.showstudent();

    person p1;
    p1.a_name = "Lisi";
    //p1.a_car = "本次";//保护权限内容，在类外访问不到
    //p1.a_password = 123;//私有权限内用，类外访问不到

    p1.func01("lisi", "benc", 123);

    //4.1.2
    b1 ok;
    //ok.a=100;


    b2 oko;
    oko.a = 100;

    //4.1.3
    pson p;
    //姓名设置
    p.setname("wangwu");

    cout << "姓名:" << p.ahowname() << endl;
    //年龄获取
    cout << "年龄:" << p.getage() << endl;

    p.setido("小米");

    //案例1：
    cube z1;
    z1.setl(10);
    z1.setw(10);
    z1.seth(10);

    cout << "z1的面积为：" << z1.calculates() << endl;
    cout << "z1的体积为：" << z1.calculatev() << endl;

    cube z2;
    z2.setl(10);
    z2.setw(10);
    z2.seth(10);

    bool ret = issame(z1, z2);
    if (ret) {
        cout << "z1和z2是相等的！" << endl;
    }
    else {
        cout << "z1和z2不相等！" << endl;
    }
    //利用成员函数判断
    ret = z1.issamebyclass(z2);
    if (ret) {
        cout << "成员函数判断：z1和z2是相等的！" << endl;
    }
    else {
        cout << "成员函数判断：z1和z2不相等！" << endl;
    }


    return 0;
}
