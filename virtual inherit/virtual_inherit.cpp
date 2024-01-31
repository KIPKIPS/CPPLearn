#include <iostream>
using namespace std;
//虚继承
//如果一个派生类从多个基类派生 而这些基类又有一个共同的基类 则在对该基类中声明的名字进行访问时 可能产生二义性
class Root
{
public:
    int num;
    Root(int n)
    {
        num = n;
        cout << "root ctor" << endl;
    }
};

class A:virtual public Root
{
public:
    int a;
    A(int n1,int n2):Root(n1)
    {
        a = n2;
        cout << "A ctor" << endl;
    }
};
class B:virtual public Root
{
public:
    int b;
    B(int n1,int n2):Root(n1)
    {
        b = n2;
        cout << "B ctor" << endl;
    }
};

class C:public A,public B
{
public:
    int c;
    C(int n1,int n2,int n3,int n4):Root(n1),A(n1,n2),B(n1,n3)
    {
        c = n4;
        cout << "C ctor" << endl;
    }
};
void main()
{
    C c(1,2,3,4);
    cout << c.num << endl;
    cin.get();
}