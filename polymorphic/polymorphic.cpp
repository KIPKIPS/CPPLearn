#include <iostream>
using namespace std;
//多态的实现原理 当编译器编译含有虚函数的类时 会为这个类创建一个虚函数表 VTable
// 虚函数表是一个存储类成员函数指针的数据结构 相当于一个指针数组存放每个虚函数的入口地址
//编译器会为该类添加一个额外的数据成员 这个数据成员是一个指向虚函数表的指针 通常称为 vptr
class Base
{
public:
    virtual void print()
    {
        cout << "base print" << endl;
    }
};

class Derived : public Base
{
public:
    virtual void print()
    {
        cout << "derived print" << endl;
    }
};

void print(Base &b)
{
    b.print();
}

int main()
{
    Base b;
    Derived d;
    Base* pb;
    pb = &b;
    pb->print();
    print(*pb);
    pb = &d;
    pb->print();
    print(*pb);

    cin.get();

    return 0;
}
