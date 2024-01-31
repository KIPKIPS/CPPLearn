#pragma once
#include "Character.h"

class Priest : public Character
{
public:
    int itn;
    Priest(int itn, int hp, int mp, int def, int res, int atk);

    void Attack();
    void Skill();
};
