#include <iostream>
using namespace std;
//多态的实现原理 当编译器编译含有虚函数的类时 会为这个类创建一个虚函数表 VTable
// 虚函数表是一个存储类成员函数指针的数据结构 相当于一个指针数组存放每个虚函数的入口地址
//编译器会为该类添加一个额外的数据成员 这个数据成员是一个指向虚函数表的指针 通常称为 vptr

//重载 同一作用域下 函数名相同 但参数列表不同
//重写 在基类和派生类中(不同作用域下) 函数名相同 返回类型相同 且基类函数必须为虚函数
//重定义 在基类和派生类中(不同作用域下) 函数名相同 不构成重写的则为重定义(参数列表可以相同也可以不同)
class Base
{
public:
    virtual void print()
    {
        cout << "base print" << endl;
    }
    virtual void base_func();//纯虚函数
};

class Derived : public Base
{
public:
    virtual void print()
    {
        cout << "derived print" << endl;
    }
    virtual void base_func()
    {
        
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
