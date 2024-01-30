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

int cube(int i);
int const_cube(const int i);
int ptr_cube(int* i);
bool compare(int num1, int num2 = 100);

int& sum2(int a, int b, int& sum);
inline int inline_sum(int a, int b) { return a + b; }

constexpr int fact(int n)
{
    return n == 1 ? 1 : fact(n - 1) * n;
}

constexpr int fact_num = 5;

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


    // int i = 0;
    // int* const p1 = &i; //  不能改变 p1 的值，这是一个顶层
    // const int ci = 42; //  不能改变 ci 的值，这是一个顶层
    // const int* p2 = &ci; //  允许改变 p2 的值，这是一个底层
    // const int* const p3 = p2; //  靠右的 const 是顶层 const，靠左的是底层 const
    // const int& r = ci; //  所有的引用本身都是顶层 const，因为引用一旦初始化就不能再改为其他对象的引用，这里用于声明引用的 const 都是底层 const

    //num1为int类型的变量 可以修改它的值
    //num2为int类型的常量 不可以修改它的值
    int num1 = 10;
    const int num2 = 10;
    num1 = 20;
    // num2 = 20;//错误

    //普调指针 可以修改p1的值 也可以通过修改*p1修改num1的值 只能用int类型的值来初始化 不能用const int类型 不能修改常量的值
    int* p1 = &num1;
    //int *p2 = &num2;//错误

    //底层const 可以修改指针 p3 p4 但是不可以通过*p3 *p4修改num1 num2的值
    //可以使用int类型或const int类型的数据来初始化
    const int* p3 = &num1;
    const int* p4 = &num2;
    // p3 = &num2;
    // p4 = &num1;

    //顶层const 不可以修改指针p5 p6 但是可以通过*p5修改num1的值
    //只能使用int类型的数据来初始化 不能用const int
    int* const p5 = &num1;
    // int * const p6 = &num2; //错误

    //int类型的引用可以通过r1修改num1的值 所以只能使用int类型初始化 不能使用const int类型
    int& r1 = num1;
    //int &r2 = num2; //错误

    //const int类型的引用 不能修改r3 r4的值
    //可以使用int类型的数据初始化 也可以使用const int
    const int& r3 = num1;
    const int& r4 = num2;


    //参数
    cout << cube(num1) << " " << cube(num2) << endl;
    cout << const_cube(num1) << " " << const_cube(num2) << endl;
    ptr_cube(&num1);
    // &num2 = 10;错误 
    // ptr_cube(&num2); //错误 &num2不能被修改

    cout << compare(1) << endl;

    int res = sum2(1, 2, res);
    cout << res << endl;

    //内联函数
    cout << inline_sum(5, 58) << endl;

    fact(fact_num); //实参为常量 编译期间就可以计算并返回结果
    int fact_num2 = 10;
    int fact_res = fact(fact_num2); //实参为变量 在程序运行期间计算并返回结果
    cin.get();
}

int& sum2(int a, int b, int& sum)
{
    sum = a + b;
    return sum;
}

bool compare(int num1, int num2)
{
    return num1 < num2;
}

int cube(int i)
{
    return i * i * i;
}

//不能修改形参
int const_cube(const int i)
{
    // i = 10;//错误
    return i * i * i;
}

int ptr_cube(int* i)
{
    // *i = 10; 可以修改参数的实际值
    return *i * *i * *i;
}

//可以修改i 不能修改*i
int const_ptr_cube(const int* i)
{
    int j = 10;
    i = &j;
    // *i = 10; 不可以修改参数的实际值
    return *i * *i * *i;
}

//不可以修改i 可以修改*i
int ptr_const_cube(int* const i)
{
    //int j = 10;
    //*i = 10; //可以修改参数的实际值
    // i = j; //但是不可以修改i的值
    return *i * *i * *i;
}

int ref_cube(int& r)
{
    return r * r * r;
}

int const_ref_cube(const int& r)
{
    // r = r * r * r;//错误
    return r * r * r;
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
