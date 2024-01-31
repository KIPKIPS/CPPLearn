#include "Warrior.h"
#include <iostream>
using namespace std;
Warrior::Warrior(int atn,int hp,int mp,int def,int res,int atk):Character(hp,mp,def,res,atk)
{
    this -> atn = atn;
}
void Warrior::Attack()
{
    cout << "Warrior Attack" << endl;
}
void Warrior::Skill()
{
    cout << "Warrior Skill" << endl;
}

