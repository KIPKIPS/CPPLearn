#include "Base.h"
#include <iostream>
using namespace std;

void Base::print()
{
    cout << bnum1 << " Base " << bnum2 << endl;
}
Base::Base(){
    cout << "default base" << endl;
}
Base::Base(int num1,int num2){
    cout << "params base" << endl;
    bnum1 = num1;
    bnum2 = num2;
}
Base::~Base()
{
    cout << "destroy base" << endl;
}
