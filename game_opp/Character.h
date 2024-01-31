#pragma once

class Character
{
public:
    int hp;
    int mp;
    int def;
    int res;
    int atk;
    Character(int hp,int mp,int def,int res,int atk);
    ~Character();
    void Attack();
    void Skill();
    
};
