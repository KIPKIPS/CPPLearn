//数据抽象 继承 动态绑定
//类的三种关系
//1.包含关系 class B{
// private:A a;
//}

//2.使用关系 class B {
// public: void method(A &a)
//}

//3.继承关系 class B:public A {
//}
#include "Base.h"
#include "Derived.h"
#include <iostream>
using namespace std;

class Son1
{
private :
public :
    int son1num;
    Son1()
    {
        son1num = 0;
        cout << "son1 default constructor" << endl;
    }
    Son1(int a)
    {
        son1num = a;
        cout << "son1 params constructor" << endl;
    }
};

//son2中包含son1对象 组合关系
class Son2:public Base
{
    private :
    Son1 son1;
    public :
    Son2() :Base()
    {
        cout << "son2 default constructor" << endl;
    }
    Son2(int a,int b):son1(a),Base(a,b)
    {
        cout << "son2 params constructor" << endl;
    }
};

void main()
{
    // Base b1;
    // b1.bnum1 = 10;
    // b1.bnum2 = 20;
    // b1.print();
    // Derived d1;
    // d1.dnum1 = 30;
    // // d1.pnum1 = 20;
    // d1.print();
    // d1.Base::print();
    //
    // Parent p1;
    
    // Derived d;
    //
    // Base b = d;//咏派生类的对象赋值给基类的对象
    // b.print();
    //
    // Base &b1 = d;//派生类的对象赋值给基类引用
    // b1.print();
    //
    // Base *b2 = &d;//基类指针可以指向派生类的地址
    // b2->print();

    Base b1;
    Base b2(1,2);

    Derived d1;
    Derived d2(1,2);
    cin.get();
}
