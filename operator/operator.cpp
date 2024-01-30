using namespace std;
#include <iostream>

class vector2
{
public :
    int x;
    int y;
    vector2();
    vector2(int x = 0, int y = 0);
    ~vector2();
    void print();

    //运算符重载+ 作为成员函数重载 函数的参数列表数量比运算对象少一,this指针隐式的指向左侧运算对象
    // vector2 operator+(const vector2&);

    //作为友元函数重载 参数列表数量和运算对象个数相等 
    friend vector2 operator+(const vector2&, const vector2&);
};

vector2::vector2()
{
    x = 0;
    y = 0;
}

vector2::vector2(int x, int y)
{
    this->x = x;
    this->y = y;
}

vector2::~vector2()
{
}

void vector2::print()
{
    cout << "x:" << x << ",y:" << y << endl;
}

// //作为成员函数重载
// vector2 vector2::operator+(const vector2& v)
// {
//     return vector2(this->x + v.x, this->y + v.y);
// }
//友元函数重载运算符
vector2 operator+(const vector2& v1, const vector2& v2)
{
    return vector2(v1.x + v2.x, v1.y + v2.y);
}


//运算符重载练习
class Time
{
private:
    int hours_;
    int minutes_;
public :
    Time(int hour = 0, int minute = 0);
    ~Time();
    void show_time();
    Time operator+(const Time &t);
    Time operator-(const Time &t);
    Time operator*(const Time &t);
    Time operator/(const Time &t);
};

Time::Time(int h, int m)
{
    hours_ = h;
    minutes_ = m;
}

Time::~Time()
{
}

void Time::show_time()
{
    cout << hours_ << " : " << minutes_ << endl;
}
Time Time::operator+(const Time& t)
{
    int m = minutes_ + t.minutes_;
    return Time(hours_ + t.hours_ + m / 60,(minutes_ + t.minutes_) % 60);
}



void main()
{
    // vector2 v1(2, 2);
    // vector2 v2(3, 3);
    // // v1.operator+(v2).print();//用法一 必须成员函数重载运算符
    // operator+(v1, v2).print(); //用法一 友元函数重载运算符
    // (v1 + v2).print(); //用法二

    Time t1(2,55);
    t1.show_time();

    
    cin.get();
}
