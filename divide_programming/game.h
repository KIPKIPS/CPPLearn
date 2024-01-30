#pragma once
#ifndef GAME_H_
#define GAME_H_

#include<string>
using namespace std;

struct Game
{
    string name;
    float score;
};

void input(Game games[], int size);
void sort(Game games[], int size);
void print(const Game games[], const int size);

const int Size = 5;
#endif