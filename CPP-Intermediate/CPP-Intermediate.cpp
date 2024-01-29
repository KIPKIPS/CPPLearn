// CPP-Intermediate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

//函数声明
void greet();
int sum(int a, int b);
int reset_int(int i);
void reset_int_ref(int& i);
void reset_int_address(int* i);
void get_min_max(int num1, int num2, int num3, int* min, int* max);

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

    // //参数传递
    // int i = 10;
    // int j = reset_int(i); //传了值的拷贝
    // cout << j << endl;
    // cout << i << endl;
    //
    // //当值拷贝消耗太大时,如一个复杂的结构体,适合传递引用进行操作
    // reset_int_ref(i); //传了地址
    // cout << i << endl;
    // reset_int_address(&i); //传了地址 修改了地址的值
    // cout << i << endl;
    //
    // //获取最大最小值
    // int min, max;
    // get_min_max(5, 8, 1, &min, &max);
    // cout << "min: " << min << " max: " << max << endl;

    //const的实参和形参
    //顶层const 任意的对象是常量
    //底层const 与指针和引用等复合类型有关
    //对指针而言,顶层const表示指针本身是个常亮,而底层const表示指针所指的对象是一个常量

    // // int a = 10;
    // // int *p1 = &a;
    // // int p2 = *p1;
    // int i = 10;
    // int j = 20;
    // const int ci = 20;//顶层
    // const int cii = 40;//顶层
    // const int *pi = &ci;//底层
    // cout << *pi << endl;
    // pi = &cii;
    // cout << *pi << endl;
    // int* const pii = &i;//顶层
    // // pii = &j;//禁止修改 pii是个常量
    // *pii = 666;


    int i = 0;
    int *const p1 = &i;     //  不能改变 p1 的值，这是一个顶层
    const int ci = 42;      //  不能改变 ci 的值，这是一个顶层
    const int *p2 = &ci;    //  允许改变 p2 的值，这是一个底层
    const int *const p3 = p2;   //  靠右的 const 是顶层 const，靠左的是底层 const
    const int &r = ci;      //  所有的引用本身都是顶层 const，因为引用一旦初始化就不能再改为其他对象的引用，这里用于声明引用的 const 都是底层 const

    const int &x = i;
    cin.get();
}


void get_min_max(int num1, int num2, int num3, int* min, int* max)
{
    *min = num1 > num2 ? num2 : num1;
    *min = *min > num3 ? num3 : *min;

    *max = num1 > num2 ? num1 : num2;
    *max = *max > num3 ? *max : num3;
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

void reset_int_address(int* i)
{
    *i *= 2;
}
