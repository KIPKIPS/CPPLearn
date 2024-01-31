#include <iostream>
using namespace std;

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
const int MINUTE_PRE_HOUR = 60;
const int SECOND_PRE_MINUTE = 60;
const int SECOND_PRE_HOUR = 3600;

class Time
{
private:
    int hours_;
    int minutes_;
public :
    Time(int hour = 0, int minute = 0);
    ~Time();
    void print();
    int to_minutes();
    int to_seconds();
    int to_minutes(const Time& t);
    Time operator+(const Time& t);
    Time operator-(const Time& t);
    Time operator*(int n);
    Time operator/(int n);

    enum TimeType
    {
        Minute = 0,
        Second = 1,
    };

    //自增自减运算符
    //涉及前置后置的情况
    //前置
    Time& operator++();
    // friend Time& operator++(Time& t);//友元函数实现
    Time& operator--();
    // friend Time& operator--(Time& t);//友元函数实现

    //后置 需要使用int占位符
    Time operator++(int);
    // friend Time operator++(Time& t,int);
    Time operator--(int);
    // friend Time operator--(Time& t,int);

    // =(赋值运算符)
    // Time t1 = t2;有新的对象产生 调用拷贝构造函数 Time(const Time& t);
    // t1 = t2 = t3;//没有新对象产生 调用重载的赋值运算符 Time& operator=(const Time& t);
    // 当程序没有显式的提供一个以本类或本类的引用为参数的赋值运算符重载函数时,编译器为会自动生成这样一个赋值运算符重载函数和拷贝构造函数
    // 拷贝构造函数使用传入对象的值生成一个新的对象的实例,赋值运算符是将对象的值赋值给另一个已经存在的实例
    //不包含指针的类 不需要自定义的赋值运算符和拷贝运算符 编译器会给每个类创建一个默认的拷贝构造函数和默认的赋值运算符 当类包含指针或者任何需要运行时分配的资源时,编译器生成的这两个函数可能会失效 则需要自定义赋值运算符和拷贝构造函数

    //赋值运算符重载函数
    Time& operator=(const Time& t);
    //拷贝构造函数实现
    Time(const Time& t);

    //复合的运算符
    Time& operator+=(const Time& t);
    Time& operator-=(const Time& t);
    Time& operator*=(int n);
    Time& operator/=(int n);

    //输出运算符 << 输入运算符>>
    friend ostream& operator<<(ostream& os, const Time& t); //需要为友元函数 因为需要返回ostream对象引用
    friend istream& operator>>(istream& is, Time& t); //需要为友元函数 因为需要返回ostream对象

    //关系运算符
    bool operator==(const Time& t);
    bool operator>=(const Time& t);
    bool operator<=(const Time& t);
    bool operator>(const Time& t);
    bool operator<(const Time& t);
    bool operator!=(const Time& t);

    //函数调用运算符重载
    //可以像使用函数一样使用类对象
    //函数调用运算符必须是成员函数
    //一个类可以定义多个不同版本的调用运算符 参数数量和类型上需要不同
    int operator()(const TimeType type = Second);
};

int Time::to_minutes()
{
    return hours_ * MINUTE_PRE_HOUR + minutes_;
}

int Time::to_seconds()
{
    return hours_ * SECOND_PRE_HOUR + minutes_ * SECOND_PRE_MINUTE;
}

int Time::to_minutes(const Time& t)
{
    return t.hours_ * MINUTE_PRE_HOUR + t.minutes_;
}

Time::Time(int h, int m)
{
    hours_ = h;
    minutes_ = m;
}

Time::~Time()
{
}

void Time::print()
{
    cout << hours_ << " : " << minutes_ << endl;
}

Time Time::operator+(const Time& t)
{
    return {hours_ + t.hours_ + (minutes_ + t.minutes_) / MINUTE_PRE_HOUR, (minutes_ + t.minutes_) % MINUTE_PRE_HOUR};
}

Time Time::operator-(const Time& t)
{
    int m = (hours_ - t.hours_) * MINUTE_PRE_HOUR + (minutes_ - t.minutes_);
    return {m / MINUTE_PRE_HOUR, abs(m % MINUTE_PRE_HOUR)};
}

Time Time::operator*(const int n)
{
    int m = to_minutes() * n;
    return {m / MINUTE_PRE_HOUR, m % MINUTE_PRE_HOUR};
}

Time Time::operator/(const int n)
{
    int m = to_minutes() / n;
    return {m / MINUTE_PRE_HOUR, m % MINUTE_PRE_HOUR};
}

//前置自增运算符
Time& Time::operator++()
{
    int m = to_minutes();
    m++;
    hours_ = m / MINUTE_PRE_HOUR;
    minutes_ = m % MINUTE_PRE_HOUR;
    return *this;
}

// 友元函数实现
// Time& operator++(Time& t)
// {
//     int m = t.to_minutes();
//     m++;
//     t.hours_ = m / MINUTE_PRE_HOUR;
//     t.minutes_ = m % MINUTE_PRE_HOUR;
//     return t;
// }

//前置自减运算符
Time& Time::operator--()
{
    int m = to_minutes();
    m--;
    hours_ = m / MINUTE_PRE_HOUR;
    minutes_ = m % MINUTE_PRE_HOUR;
    return *this;
}

// 友元函数实现
// Time& operator--(Time& t)
// {
//     int m = t.to_minutes();
//     m--;
//     t.hours_ = m / MINUTE_PRE_HOUR;
//     t.minutes_ = m % MINUTE_PRE_HOUR;
//     return t;
// }

//后置自增运算符
Time Time::operator++(int)
{
    // Time t = *this;
    // int m = to_minutes() + 1; 
    // hours_ = m / MINUTE_PRE_HOUR;
    // minutes_ = m % MINUTE_PRE_HOUR;
    // return t;

    int m = to_minutes();
    hours_ = (m + 1) / MINUTE_PRE_HOUR;
    minutes_ = (m + 1) % MINUTE_PRE_HOUR;
    return {m / MINUTE_PRE_HOUR, m % MINUTE_PRE_HOUR};
}

//后置自减运算符
Time Time::operator--(int)
{
    int m = to_minutes();
    hours_ = (m - 1) / MINUTE_PRE_HOUR;
    minutes_ = (m - 1) % MINUTE_PRE_HOUR;
    return {m / MINUTE_PRE_HOUR, m % MINUTE_PRE_HOUR};
}

//赋值运算符
Time& Time::operator=(const Time& t)
{
    hours_ = t.hours_;
    minutes_ = t.minutes_;
    cout << "assign" << endl;
    return *this;
}

//拷贝构造函数
Time::Time(const Time& t)
{
    hours_ = t.hours_;
    minutes_ = t.minutes_;
    cout << "copy" << endl;
}

Time& Time::operator+=(const Time& t)
{
    *this = *this + t;
    return *this;
}

Time& Time::operator-=(const Time& t)
{
    *this = *this - t;
    return *this;
}

Time& Time::operator*=(int n)
{
    *this = *this * n;
    return *this;
}

Time& Time::operator/=(int n)
{
    *this = *this / n;
    return *this;
}

ostream& operator<<(ostream& os, const Time& t)
{
    return os << t.hours_ << " : " << t.minutes_ << endl;
}

istream& operator>>(istream& is, Time& t)
{
    is >> t.hours_ >> t.minutes_;
    if (!is) t = Time();
    return is;
}

bool Time::operator==(const Time& t)
{
    return to_minutes() == to_minutes(t);
}

bool Time::operator>=(const Time& t)
{
    return to_minutes() >= to_minutes(t);
}

bool Time::operator<=(const Time& t)
{
    return to_minutes() <= to_minutes(t);
}

bool Time::operator>(const Time& t)
{
    return to_minutes() > to_minutes(t);
}

bool Time::operator<(const Time& t)
{
    return to_minutes() < to_minutes(t);
}

bool Time::operator!=(const Time& t)
{
    return to_minutes() != to_minutes(t);
}

int Time::operator()(const TimeType type)
{
    switch (type)
    {
    case Minute: return to_minutes();
    case Second: return to_seconds();
    }
    return to_seconds();
}

void main()
{
    // // vector2 v1(2, 2);
    // // vector2 v2(3, 3);
    // // // v1.operator+(v2).print();//用法一 必须成员函数重载运算符
    // // operator+(v1, v2).print(); //用法一 友元函数重载运算符
    // // (v1 + v2).print(); //用法二
    //
    // // Time t1(0, 15);
    // Time t2(2, 55);
    // // (t1 + t2).print();
    // // (t1 - t2).print();
    // // (t1 * 5).print();
    // // (t2 / 5).print();
    // // (++t2).print();
    //
    // Time t3(0, 0);
    // t2 = t3++;
    // t2.print();
    // t3.print();
    //
    // Time t4(0, 0);
    // t2 = t4--;
    // t2.print();
    // t4.print();


    // Time t1(0, 15);
    // Time t2 = t1;
    // Time t3;
    // t3 = t1;
    // t2.print();
    // t3.print();
    //
    // t2 += t3;
    // t2.print();

    // Time t1(1,1);
    // Time t2;
    // cout << t1 << endl;
    // cin >> t2;
    // cout << t2 << endl;
    Time t1(1, 20);
    Time t2(0, 80);
    // cout << (t1 == t2) << endl;
    cout << t1() << endl;
    cin.get();
}
