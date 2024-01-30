// divide_programming.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "game.h"
using namespace std;

int main()
{
    cout << "enter 5 games:" << endl;

    Game games[Size] = {};
    input(games,Size);
    sort(games,Size);
    print(games,Size);
}