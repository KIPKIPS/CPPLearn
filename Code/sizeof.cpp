#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int a;
    int *p;
    p = &a;
    a = 5;
    printf("%d", sizeof(a));
    printf("%d", sizeof(&a)); //a的地址
    printf("%d", sizeof(*p)); //p存储的值
    printf("%d", sizeof(&p)); //p的地址

    long long b = 10;
    short c = 1;
    char d = 'a';
    char *str = "wangkunpeng is my father,fuck c++,holy shit language!";
    cout << "size:" << sizeof(b) << endl;
    cout << "size:" << sizeof(c) << endl;
    cout << "size:" << sizeof(d) << endl;
    cout << "size:" << sizeof(str) << endl;
    cout << "length:" << strlen(str) << endl;
    system("pause");
    return 0;
}