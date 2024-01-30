#include "student.h"
//使用::作用域解析符来标识函数所属的类
void student::set_student(const string& name, const int chinese, const int math, const int english)
{
    name_ = name;
    chinese_ = chinese;
    math_ = math;
    english_ = english;
}
//构造函数
student::student(){}
student::student(const string& name,int chinese,int math,int english)
{
    //this访问自身对象的数据成员以及方法
    // this -> set_student(name,chinese,math,english);
    set_student(name,chinese,math,english);
}
//析构函数 类对象被销毁的时候 自动调用
student::~student()
{
    
}


int student::sum()
{
    //this访问自身对象的数据成员以及方法
    return this -> chinese_ + math_ + english_;
}

float student::average(){
    return float(chinese_ + math_ + english_) / 3;
}

bool student::pass(){
    return chinese_ >= pass_score && math_  >= pass_score && english_ >= pass_score;
}

int student::compare(student &s)
{
    if (this -> sum() > s.sum())
    {
        return 1;
    }
    if(this -> sum() == s.sum())
    {
        return 0;
    }
    return -1;
}