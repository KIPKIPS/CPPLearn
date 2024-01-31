#include <iostream>
using namespace std;

//只有纯虚函数的类称为抽象类
class Shape
{
public :
    virtual double area() = 0;//纯虚函数需要 = 0
    virtual double volumn() = 0;
};

class Cube : public Shape
{
private:
    float wide;
public :
    Cube(float wide = 0)
    {
        this->wide = wide;
    }

    ~Cube()
    {
    }

    virtual double area()
    {
        return wide * wide * 6;
    }

    virtual double volumn()
    {
        return wide * wide * wide;
    }
};

class Cubiod : public Shape
{
private:
    float length;
    float wide;
    float height;
public:
    Cubiod(float l = 0,float w = 0,float h = 0)
    {
        length = l;
        wide = w;
        height = h;
    }
    ~Cubiod(){}
    virtual double area()
    {
        return (length * wide + length * height + height * wide) * 2;
    }
    virtual double volumn()
    {
        return length * height * wide;
    }
};
void cal(Shape &s,double &area,double &vol);


int main()
{
    Cube cube(10);
    Cubiod cubiod(1.5f,2,4);

    double area;
    double volumn;
    cal(cube,area,volumn);
    cout << area << endl;
    cout << volumn << endl;
    cal(cubiod,area,volumn);
    cout << area << endl;
    cout << volumn << endl;

    Shape* s;
    s = &cube;
    cout << s->area() << " " << s->volumn()<<endl;
    s = &cubiod;
    cout << s->area() << " " << s->volumn()<<endl;
    cin.get();
    return 0;
}

void cal(Shape &s,double &area,double &vol)
{
    area = s.area();
    vol = s.volumn();
}
