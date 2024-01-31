#pragma once
#include "Character.h"

class Warrior : public Character
{
public:
    int atn;
    Warrior(int atn, int hp, int mp, int def, int res, int atk);

    void Attack();
    void Skill();
};
