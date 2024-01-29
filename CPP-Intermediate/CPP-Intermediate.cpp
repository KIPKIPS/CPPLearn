// CPP-Intermediate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

//函数声明
void greet();
int sum(int a, int b);
int reset_int(int i);
void reset_int_ref(int & i);


int main()
{
    // for (int i = 0; i < 10; ++i)
    // {
    //     greet();
    // }
    // string a;
    // string b;
    // cout << "enter first number: ";
    // getline(cin, a);
    // cout << "enter second number: ";
    // getline(cin, b);
    // cout << a << " + " << b << " = " << sum(stoi(a), stoi(b)) << endl;

    //参数传递
    int i = 10;
    int j = reset_int(i);
    cout << j << endl;
    cout << i << endl;
    reset_int_ref(i);
    cout << i << endl;
    cin.get();
}

void greet()
{
    cout << "hello" << endl;
    static int count = 0;
    count++;
    cout << "执行了" << count << "次" << endl;
}

int sum(int a, int b)
{
    return a + b;
}

int reset_int(int i)
{
    return i * 2;
}

void reset_int_ref(int& i)
{
    i *= 2;
}
