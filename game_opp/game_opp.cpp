#include <iostream>
using namespace std;
#include "Mage.h"
#include "Priest.h"
#include "Warrior.h"

void main()
{
    Warrior w(10,10,10,20,50,80);
    Mage m(10,10,10,20,50,80);
    Priest p(10,10,10,20,50,80);
    w.Skill();
    w.Attack();

    m.Skill();
    m.Attack();

    p.Skill();
    p.Attack();
    cin.get();
}
