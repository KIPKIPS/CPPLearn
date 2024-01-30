//函数结构体
#include <chrono>
#include <iostream>
#include <string>
using namespace std;
struct work_time
{
    int hours;
    int mins;
    void print()
    {
        cout << hours <<"hours"<<mins<<"minutes"<<endl;
    }
};
work_time sum(const work_time &t1, const work_time &t2);

const int mins_per_hour = 60;

void main()
{
    work_time t1 {
        12,55,
    };
    work_time t2 {
        1,35,
    };
    sum(t1,t2).print();
}
work_time sum(const work_time &t1, const work_time &t2)
{
    work_time total{};
    total.mins = (t1.mins + t2.mins) % mins_per_hour;
    total.hours = (t1.mins + t2.mins) / mins_per_hour + t1.hours + t2.hours;
    return total;
}
