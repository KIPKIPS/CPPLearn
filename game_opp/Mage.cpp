#include "Mage.h"
#include <iostream>
using namespace std;
Mage::Mage(int itn,int hp,int mp,int def,int res,int atk):Character(hp,mp,def,res,atk)
{
    this -> itn = itn;
}
void Mage::Attack()
{
    cout << "Mage Attack" << endl;
}
void Mage::Skill()
{
    cout << "Mage Skill" << endl;
}