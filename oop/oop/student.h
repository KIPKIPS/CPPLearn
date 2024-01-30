#pragma once
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
#include <string>

//关键字和类名
class student
{
    //私有成员
    string name_;
    int chinese_ = 0;
    int math_ = 0;
    int english_ = 0;
    void set_student(const string& name,int chinese,int math,int english);
    static int pass_score = 60;
    
    //公共成员
    public:
    ~student();//析构函数
    student();//默认构造函数
    student(const string& name,int chinese,int math,int english);//构造函数
    int sum();
    float average();
    bool pass();
    int compare(student &s);
};

#endif

