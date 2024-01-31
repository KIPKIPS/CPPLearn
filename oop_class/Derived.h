#pragma once
#include "Base.h"
#include "Parent.h"

class Derived:public Base,protected Parent
{
public:
    int dnum1;
    void print();
    Derived();
    Derived(int num1,int num2);
    ~Derived();
};
