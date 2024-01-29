// HelloCPP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <climits>;
using namespace std;

void int_type()
{
	short a = 3; //32768 到32767
	int b = 100;
	long c = 900;
	long long d = 1000;

	cout << "INT_MIN: " << INT_MIN << " -- INT_MAX: " << INT_MAX << endl;
	cout << "SHRT_MIN: " << SHRT_MIN << " -- SHRT_MAX: " << SHRT_MAX << endl;
	cout << "LONG_MIN: " << LONG_MIN << " -- LONG_MAX: " << LONG_MAX << endl;

}
void char_type() {
	char a = 'a';
	int toInt = 'a';
	cout << a << " ascii: " << toInt << endl;
	char c = 99;
	cout << c << endl;
}

void float_type() {
	float f = 3.4E2;
	cout << f << endl;
	f = 3.4e3;
	cout << f << endl;
	f = 3.4e-3;
	cout << f << endl;
	f = -3.4E-4;
	cout << f << endl;

	cout << "FLOAT_MAX: " << FLT_MAX << endl;
	cout << "FLOAT_MIN: " << FLT_MIN << endl;

	long float lf = 1.0f;

}

void arithmetic_operator() {
	int a1;
	int a2;
	/*cout << "算术运算符" << endl;
	cout << "第一个数字:";
	cin >> a1;
	cout << "第二个数字:";
	cin >> a2;
	cout << a1 + a2 << endl;
	cout << a1 - a2 << endl;
	cout << a1 * a2 << endl;
	cout << (float)a1 / a2 << endl;*/

	cout << 10 % 2 << endl;
	cout << 41 / 7 * 2 << endl;
	cout << 3 % 2 * 2 << endl;
	cout << 3 * 7 % 5 << endl;
}

void keyword_auto() {
	/*auto a = 11;
	cout << "输入总秒数:";
	int total;
	cin >> total;
	int hour = total / 3600;
	int minute = (total - hour * 3600) / 60;
	int second = total - hour * 3600 - minute * 60;
	string hs = to_string(hour);
	hs = hs.length() >= 2 ? hs : ("0" + hs);
	string ms = to_string(minute);
	ms = ms.length() >= 2 ? ms : ("0" + ms);
	string ss = to_string(second);
	ss = ss.length() >= 2 ? ss : ("0" + ss);
	cout << hs << ":" << ms << ":" << ss << endl;*/
}

void array_type() {
	int int_array[10];
	int int_array2[4] = { 1,2,3,4 };
	int int_array3[4][2] = { {1,2},{3,4},{5,6},{7,8} };
	int int_array4[] = { 1,2,3 };
	int int_array5[]{ 1,2,3,4,5 };
	//char char_array[10][10];

	char empty = '\0';//空字符串
	char c1[] = { 'k','i','p','s' };
	char c2[] = { 'k','i','p','s','\0','?' };
	//输出字符串数组会直接运行到\0结束
	cout << c2;
	//cout << c1;
	char kips[] = "kips.cc";
	cout << strlen(kips) << endl;
	char str[] = "my name is kips,"
		"what's your name?";
	//cin按照空格进行输入拆分 ,使用获取一行来解决
	cout << "what is your name?";
	char name[30];
	cin.getline(name, 30);
	cout << "what do your like to eat?";
	char food[50];
	cin.getline(food, 50);
	cout << name << "喜欢吃" << food << endl;
}
void string_type() {
	cout << "请输入字符串: ";
	string ipt1;
	getline(cin, ipt1);
	cout << "你输入了: " << ipt1 << endl;
}

//定义结构体
struct Position {
	int x = 0;
	int y;
private:
	int dis;
public:
	void print() {
		cout << "(x:" << x << ",y:" << y << ")" << endl;
	}
	int get_dis() {
		return x * x + y * y;
	}
	void pfunc() {
		cout << "pfunc" << endl;
	}
};

void struct_type() {
	Position p1;
	p1.x = 10;
	p1.y = 100;
	p1.print();


	Position p3;
	p3.x = 2;
	p3.y = 8;
	cout << p3.get_dis() << endl;
	p3.pfunc();
}

enum Type {
	Int, Float, String, Char
};

void enum_type() {
	Type a = Int;
	a = Float;
	a = Type(2);
}

#include <array>
void point_type() {
	//&取址运算符
	//*取值运算符
	int a = 1;
	int* b = &a;
	float c = 0.1;
	cout << "a地址:" << &a << " " << b << endl;
	cout << "b地址的值:" << *b << endl;

	int* p1 = NULL;
	int* p2 = nullptr;
	void* p;//p可以接收任意类型的指针
	p = &a;
	//cout << *p << endl;//报错
	cout << "p地址的值" << *(int*)p << endl;

	int* p3 = new int;//开辟一个空间存储int类型的指针
	*p3 = 22;//这个指针没有任何变量使用 只能通过p2指针来访问
	cout << *p3 << endl;
	delete p3;//释放p2指针的内存 new申请的内存一定需要delete

	//指针类型数组
	int arr[]{ 1,2,3,4 };
	//cout << arr << endl;//输出地址
	//cout << *arr << endl;//输出索引为0的值
	//cout << *(arr + 1) << endl;//输出当前索引加一的值
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << "索引" << i << ":" << *(arr + i) << endl;
	}
	for (int i = 0; i < __crt_countof(arr); i++)
	{
		cout << "索引" << i << ":" << *(arr + i) << endl;
	}

	cout << "arr2" << endl;
	int* arr2 = new int[20];
	arr2[0] = 1;//索引设值
	*(arr2 + 1) = 2;//
	for (int i = 0; i < 2; i++)
	{
		cout << "索引" << i << ":" << arr2[i] << endl;
	}
	//delete arr2;//只会删除第一个元素
	delete[] arr2;//删除数组


	cout << "arr3" << endl; //c++ 11新语法
	//使用模板类
	array<int, 10> arr3 = { 0,1,2,3,4,5,6,7,8,9 };
	array<int, 10> arr4 = { 0,1 };
	arr4 = arr3;//array赋值必须长度一致
}

void example_for() {
	//for (int i = 0; i = 0 < 10; i = ++)
	//{
	//    cout << i << endl;
	//}
	//char c1[] = "kips";
	//char c2[] = "kips";
	//cout << (c1 == c2) << endl;//比较内存地址 结果为0
	//cout << strcmp(c1,c2) << endl;//比较内容 相等输出0
	//string s1 = "kips";
	//string s2 = "kips";
	//cout << (s1 == s2) << endl;//比较内容 相等输出1

	//int i = 0;
	//while (i < 10)
	//{
	//    cout << "while"<<i<<endl;
	//    i++;
	//}

	//int i = 0;
	//do {
	//    i++;
	//    cout << "do" << i << endl;
	//} while (i < 10);

	//数组的遍历
	//int arr[] = { 1,2,3,4 };
	//for (int t : arr)
	//{
	//	cout << t << endl;//只能遍历 不能修改
	//}
	//for (int& t : arr)
	//{
	//	t = 10;//取得的是地址,可以修改值
	//	cout << t << endl;
	//}

	//int arr2[2][3] = { {1,2,3},{2,3,4} };
	//for (int i = 0; i < 2; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		cout << i << "_" << j <<" : "<< arr2[i][j] << endl;
	//	}
	//}
}

//宏
#define END cout <<"print END"<<endl //定义宏
#define out cout <<
#define _ <<
#define end << endl;
//类型 只能给类型起名字
typedef string ks;
void example_def() {
	//类型别名
	END; //替换字符串
	ks str = "kips";
	out "字符串为:" _ str _ "。" end
}

void example_switch() {
	int value = 0;
	switch (value)
	{
	case 0 :
		out "1" end
		break;
	case 1:
		out "2" end
			break;
	case 2:
		out "3" end
			break;
	default:
		break;
	}
}

int main()
{

	//cout << "Hello World!"<<endl;
	//cout << "how old are you?" <<endl;
	//int age;
	//cin >> age;
	//cout << "you are " << age * 12 << " months" << endl;
	//cin.get();

	//int_type();
	//char_type();
	//float_type();
	//arithmetic_operator();
	//keyword_auto();
	//array_type();
	//string_type();
	//struct_type();
	//enum_type();
	//point_type();

	//example_for();
	//example_def();
	example_switch();

	cin.get();
}

//int main2()
//{
//    std::cout << "Hello World!\n";//std命名空间下的cout函数
//    std::cout << std::endl;
//    std::cout << "my first cpp code";
//    std::cin.get();
//}
