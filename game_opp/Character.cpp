#include "Character.h"
Character::Character(int hp,int mp,int def,int res,int atk)
{
    this -> hp = hp;
    this -> mp = mp;
    this -> def = def;
    this -> res = res;
    this -> atk = atk;
}
Character::~Character()
{
    
}