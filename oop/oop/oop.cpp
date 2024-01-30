//面向对象 特性: 抽象 封装和数据隐藏 多态 继承 代码的可复用性
using namespace std;
#include <iostream>
#include "student.h"

void main()
{
    student stu; 
    student stu1 = student("kips", 100, 100, 80); //显式构造函数
    // student stu1("kips", 100, 100, 80);//隐式构造函数
    cout << "total score: " << stu1.sum() << " average score: " << stu1.average() << " pass(Y/N): " << (
        stu1.pass() ? "Y" : "N") << endl;

    friend_func(stu1);
    cin.get();
}
