#include "Derived.h"
#include <iostream>
using namespace std;
void Derived::print()
{
    cout << dnum1 << " Derived " << pnum1 << endl;
}
//派生类的构造函数 需要使用:Base()调用基类的构造函数 不写的话默认调用基类的默认构造函数
//先基类 再派生类
Derived::Derived():Base()
{
    cout << "default derived" << endl;
}

Derived::Derived(int num1,int num2):Base(num1,num2)
{
    cout << "params derived" << endl;
}
//派生类的析构函数 编译器会自动调用基类的析构函数
//先派生类 再基类
Derived::~Derived()
{
    cout << "destroy derived" << endl;
}
