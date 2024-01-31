#include "Priest.h"
#include <iostream>
using namespace std;
Priest::Priest(int itn,int hp,int mp,int def,int res,int atk):Character(hp,mp,def,res,atk)
{
    this -> itn = itn;
}
void Priest::Attack()
{
    cout << "Priest Attack" << endl;
}
void Priest::Skill()
{
    cout << "Priest Skill" << endl;
}