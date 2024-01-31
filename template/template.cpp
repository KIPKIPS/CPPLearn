#include <iostream>
using namespace std;
// //函数模板
// template <typename T> T kmax(T a, T b);
// char kmax(char a, char b);
//
// void main()
// {
//     cout << kmax(2,5) << endl;
//     cout << kmax(2.5f,5.6f) << endl;
//     cout << kmax("sada","ddddd") << endl;
//     cin.get();
// }
// //函数模板
// template <typename T> T kmax(T a, T b)
// {
//     return a > b ? a : b;
// }
// //函数模板的重载
// char kmax(char a, char b)
// {
//     return a > b ? a : b;
// }
template <typename T>
class Cube
{
private:
    T wide;
public:
    Cube(T wide = 0)
    {
        this->wide = wide;
    }

    ~Cube()
    {
    }

    T area()
    {
        return wide * wide * 6;
    }

    T volumn();
};

//类模板外部定义成员函数时 需要加上模板说明 类名后面也要加上<T>
template <typename T>
T Cube<T>::volumn()
{
    return wide * wide * wide;
}

//类模板
void main()
{
    Cube<float> c1(2.5f);
    cout << c1.area() << endl;
    cout << c1.volumn() << endl;
    cin.get();
}
