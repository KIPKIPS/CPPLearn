#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    //printf("Congratulasions! It works!\n");
    int a;
    int *p;
    p = &a;
    a = 5;
    printf("pointer: Ox%p\n", p);
    printf("a: %d\n", *p); //解引用
    *p = 8;                //修改p指针指向的地址的值为8
    printf("a: %d\n", *p);
    system("pause");
    return 0;
}