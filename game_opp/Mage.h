#pragma once
#include "Character.h"

class Mage : public Character
{
public:
    int itn;
    Mage(int itn, int hp, int mp, int def, int res, int atk);

    void Attack();
    void Skill();
};
