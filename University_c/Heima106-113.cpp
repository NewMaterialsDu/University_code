
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;
//4.2对象的初始化和清理
//4.2.1构造函数和析构函数
//class person {
////1.构造函数进行初始化操作
////构造函数语法：类名（）{ }
////1.构造函数没有返回值，也不写void
////2.函数名称与类名相同
////3.构造函数可以有参数，所以可以发生函数重载
////4.程序在调用对象时会自动调用构造，无需手动调用，而且只会调用一次
//    //4.2.2构造函数的分类及调用
////按参数为有参和无参(默认构造)
//public:
//person() {
//    cout << "person无参构造函数的调用" << endl;
//}
//person(int a) {
//    age = a;
//    cout << "person有参构造函数的调用" << endl;
//}
////按类型为普通和拷贝
////拷贝
//person(const person& p) {
// //将传入的人的身上的所有属性，拷贝到我身上
//    age = p.age;
//    cout << "person拷贝构造函数的调用" << endl;
//}
////2.析构函数进行清理操作
////析构函数语法： ~类名（）{ }
////1.析构函数没有返回值也不写void
////2.函数名称与类名相同，在名称前加上符号 ~
////3.析构函数不可以有参数，因此不能发生重载
////4.程序在对象销毁前会自动调用析构，无需手动调用而且只会调用一次
//~person(){
//    cout << "person析构函数的调用" << endl;
//}
//int age;
//};

//构造和析构都是必须有的实现，如果自己不提供，编译器会提供一个空的构造和析构
//void test01() {
    ////在栈上的数据，test01（）执行完毕后，释放这个对象（释放前会调用析构函数）
    //person p1;//默认构造函数调用
    ////调用
    ////括号法
    //person p2(10);//有参构造函数
    //person p3(p2);//拷贝构造函数
    ////注意：调用默认构造函数时不要加小括号
    ////因为编译器会认为是一个函数的声明，不会认为在创建对象
    ////person p4();
    //cout << "p2的年龄是：" << p2.age << endl;
    //cout << "p3的年龄是：" << p3.age << endl;
    ////显示法
    //person p4;
    //person p5 = person(20);//有参函数
    //person p6 = person(p5);//拷贝构造
    //person(20);//匿名对象 特点：当前执行结束后，系统会立即回收匿名对象
    //cout << "aaaa" << endl;
    ////不要利用拷贝构造函数 初始化对象
    ////person(p6);//执行会报错 编译器会认为 person(p6) === person p6;//重定义了,认为是对象的声明
    ////隐式转换法
    //person p7 = 30;//相当于 person p7 = person(30); //有参构造
    //person p8 = p7;//拷贝构造
//}

//class person {
//public:
//    person() {
//        cout << "无参构造函数！" << endl;
//    }
//    person(int age) {
//        cout << "有参构造函数！" << endl;
//        mage = age;
//    }
//    person(const person& p) {
//        cout << "拷贝构造函数!" << endl;
//        mage = p.mage;
//    }
//    //析构函数在释放内存之前调用
//    ~person() {
//        cout << "析构函数！" << endl;
//    }
//public:
//    int mage;
//};
//void test02() {
//    //4.2.3拷贝构造函数的调用时机
//    //1.*使用一个已经创建完毕的对象来初始化一个新对象
//    person p1(20);
//    person p2(p1);
//    cout << "p2的年龄为：" << p2.mage << endl;
//}
//
////2.* 值传递的方式给函数参数传值
//void test04(person p3) {
//    //值传递就算改p3也不影响原来的值
//}
//void test03() {
//    person p3;
//    test04(p3);
//}
// //3.* 以值方式返回局部对象
//person test05() {
//    person p4;
//    //返回的并不是原来的p4，而是一个新的对象
//    cout << (int*)&p4 <<endl;
//    return p4;
//}
//void test06() {
//    person p5 = test05();
//    cout << (int*)&p5 << endl;
//
//}

//4.2.4构造函数的调用规则：默认情况下，c++编译器至少给一个类添加3个函数
//1.默认构造函数（无参，函数体为空）
//2.默认析构函数（无参，函数体为空）
//3.默认拷贝函数，对属性进行值拷贝
//* 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
//* 如果用户定义拷贝构造函数，c++不会再提供其他构造函数
//class person {
//public:
//    //注释掉默认无参构造后，因为已经存在有参构造，所以编译器不在提供无参构造，此时调用test02的无参就会报错
//    person() {
//        cout << "preson的默认构造函数调用" << endl;
//    }
//    person(int age) {
//        cout << "preson的有参构造函数调用" << endl;
//        mage = age;
//    }
//    //这里注释掉了，执行test01中的拷贝构造函数还是默认会有下两行的值传递
//    //person(const person& p) {
//    //    cout << "preson的拷贝构造函数调用" << endl;
//    //    mage = p.mage;//这一行值传递
//    //}
//
//    ~person() {
//        cout << "preson的默认析构函数调用" << endl;
//    }
//    int mage;
//};
//void test01() {
//    person p;
//    p.mage = 18;
//    person p2(p);
//    cout << "p2的年龄为：" << p2.mage << endl;
//}
//void test02() {
//    person p3;
//}

//4.2.5深拷贝和浅拷贝
//class person {
//public:
//    person() {
//        cout << "默认无参构造" << endl;
//    }
//    person(int age, int height) {
//        cout << "默认有参构造" << endl;
//        mage = age;
//        mheight = new int(height);//new返回的是一个地址
//    }
//    //自己实现拷贝构造，解决浅拷贝问题
//    person(const person& p) {
//        cout << "拷贝构造调用" << endl;
//        mage = p.mage;
//        //mheight = p.mheight;//默认拷贝函数（编译器）
//        //深拷贝操作
//        mheight = new int(*p.mheight);
//    }
//
//    ~person() {
//        //析构函数，将堆区开辟的空间释放
//        if (mheight != NULL) {
//            delete mheight;
//            mheight = NULL;//这里只是把一个对象的地址释放了，但另外一个并没有被命名为NULL，所以还是会发生双重释放，从而崩溃
//        }//解决办法，自己写一个拷贝函数，进行深拷贝
//        cout << "默认析构" << endl;
//    }
//
//    int mage;
//    int* mheight;
//};
//void test01() {
//    //创建的对象一般在栈上，尊顺先进后出和后进先出的规则，所以先执行p2的析构，再执行p1的析构
//    person p1(18,160);
//    cout << "p1的年龄为：" <<p1.mage<< endl;
//    cout << "p1的身高为：" << *p1.mheight << endl;
//    //使用默认拷贝函数，默认是进行浅拷贝
//    person p2(p1);
//    cout << "p2的年龄为：" << p2.mage << endl;
//    cout << "p2的身高为：" << *p2.mheight << endl;
//
//}

//4.2.6初始化列表
//class person {
//public:
//    //传统初始化
//    //person(int a,int b,int c) {
//    //    ma = a;
//    //    mb = b;
//    //    mc = c;
//    //}
//
//    //初始化列表初始化属性
//    person(int a,int b,int c) :ma(a), mb(b), mc(c) {
//        //person():ma(10),mb(20),mc(30){//两种写法对应两种调用方式
//
//    }
//    int ma;
//    int mb;
//    int mc;
//};
//void test01() {
//    person p(10, 20, 30);
//    //person p;
//    cout << "ma的值为：" << p.ma<<endl;
//    cout << "mb的值为：" << p.mb << endl;
//    cout << "mc的值为：" << p.mc << endl;
//
//}

//4.2.7类对象作为类成员
//class phone {
//public:
//    phone(string pname) {
//        m_pname = pname;
//        cout << "phone的函数构造调用" << endl;
//    }
//    ~phone() {
//        cout << "phone析构函数" << endl;
//    }
//    string m_pname;
//
//};
//
//class person {
//    public:
//        //下一行中的string pname能给phone类型的m_phone，是因为相当于，phone m_phone = pname 隐式转换法，phone中的pname也是string类型
//        person(string name,string pname):m_name(name),m_phone(pname)
//        {
//            cout << "person的函数构造调用" << endl;
//        }
//        ~person(){
//            cout << "person析构函数" << endl;
//        }
//    //姓名
//        string m_name;
//    //手机
//        phone m_phone;
//};
//
//void test01() {
//    person p("张三", "苹果MAX");
//    cout << p.m_name << "拿着：" << p.m_phone.m_pname << endl;
//}
////当其他类对象作为本类成员，构造时候先构造类对象，再构造自身，析构是相反的（栈的先进后出）

//4.2.8静态成员:在变量和函数前加上static
//成员变量：所有对象共享同一份数据；在编译阶段分配内存；类内声明，类外初始化
//成员函数：所有对象共享一个函数；静态成员函数只能访问静态成员变量
//class person {
//public:
//    static int m_a;
//    //静态对象的访问也是有权限的
//private:
//    static int m_b;
//
//   
//};
//int person::m_a = 100;
//int person::m_b = 200;
//void test01() {
//    person p;
//    cout << p.m_a << endl;
//
//    person p2;
//    p2.m_a = 200;
//    cout << p.m_a << endl;
//}
//void test02() {
//    //静态成员变量不属于某个对象上，所有对象访问同一份数据
//    //因此静态对象能通过对象和类名访问
//    person p3;
//    cout << p3.m_a << endl;
//
//    cout << person::m_a << endl;
//    //cout << person::m_b << endl;//
//}

//静态成员函数
//class person {
//public:
//    
//    static void func1() {
//        m_a = 100;//静态函数只能访问静态变量
//        //m_b = 200;
//        cout << "static void funci()" << endl;
//    }
//    int m_b;
//    static int m_a;
//    //和静态变量一样，也是有访问权限的
//};
//int person::m_a = 0;
////两种访问方式
//void test01() {
//    //通过对象访问
//    person p;
//    p.func1();
//    //通过类名访问
//    person::func1();
//}
int main()
{
    //4.2
    //4.2.1
        //test01();
        //person p1;//主函数没有执行完，所以不会调用析构

        //4.2.3
        //test02();
        //test03();
        //test06();
        //4.2.4
        //test01();
        //test02();
        //4.2.5   
        //test01();
        //4.2.6
        //test01();
        //4.2.7
        //test01();
        //4.2.8
        //test01();
        //test02();
        //test01();
    system("pause");
    return 0;
}
