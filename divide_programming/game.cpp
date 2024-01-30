#include "game.h"

#include <algorithm>
#include <iostream>
using namespace std;
void input(Game games[], int size) {
    for (int i = 0; i < size; ++i)
    {
        cout << "input game name: ";
        cin >> games[i].name;
        cout << "input game score: ";
        cin >> games[i].score;
    }
}
//降序
void sort(Game games[], int size) {
    Game tmp;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (games[i].score < games[j].score)
            {
                tmp = games[i];
                games[i] = games[j];
                games[j] = tmp;
            }
        }
    }
}
void print(const Game games[], const int size) {
    for (int i = 0; i < size; ++i)
    {
        cout << "NO." << i + 1 <<" Game Name: "<< games[i].name << " Game Score: " << games[i].score << endl;
    }
}