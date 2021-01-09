#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define day 7         //宏常量
const int month = 12; //const修饰的变量
int main()
{
    const int year = 2021;
    printf("define: %d,const: %d,inside const:%d", day, month, year);
    system("pause");
}