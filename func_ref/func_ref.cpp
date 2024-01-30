//函数指针
//函数和数据相似 函数也有地址 函数的地址是存储其机器语言代码内存的开始地址 可以将地址作为函数的参数 使得第一个函数可以找到第二个函数并运行他
//函数指针指向的函数而不是对象
//使用指针替换函数名即可声明一个指向函数的指针
#include <iostream>
#include <string>
using namespace std;
bool compare(const string &,const string &,void (const string &,const string &) = nullptr,void (const string &,const string &) = nullptr);
void morethan(const string &,const string &);
void lessthan(const string &,const string &);
void main()
{
    string s1 = "kips";
    string s2 = "wkp";
    bool res = compare(s1,s2);
    cout << res << endl;

    //函数指针的定义和赋值
    void (*c1)(const string &,const string &) = morethan;
    void (*c2)(const string &,const string &) = lessthan;
    bool (*func)(const string &,const string &,void (const string &,const string &),void (const string &,const string &)) = compare;
    auto rlt = func(s2,s1,c1,c2);
    cout << rlt << endl;

    cin.get();
}

void morethan(const string &s1,const string &s2)
{
    cout << s1 << " > " << s2 << endl;
}

void lessthan(const string &s1,const string &s2)
{
    cout << s1 << " < " << s2 << endl;
}

bool compare(const string &s1,const string &s2,void (*greater)(const string &,const string &),void (*less)(const string &,const string &))
{
    auto rlt = s1.length() > s2.length() ? true : false;
    if (greater && less)
    {
        if (rlt)
        {
            greater(s1,s2);
        }else
        {
            less(s1,s2);
        }
    }
    return rlt;
}
