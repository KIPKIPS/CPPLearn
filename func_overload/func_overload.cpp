//函数重载
#include <iostream>
#define LINE_FEED cout << endl;
using namespace std;
void print(const char *cp);
void print(const int *start,const int *end);
void print(const int array[],size_t size);
void main()
{
    //1
    char c = 'k';
    print(&c);
    LINE_FEED
    
    //2
    int arr[]{1,2,3,4,5};
    print(&arr[0],&arr[size(arr)]);
    LINE_FEED
    //3
    print(arr,size(arr));
    LINE_FEED
    cin.get();
}

void print(const char *cp)
{
    cout << "1: " << *cp <<endl;
}

void print(const int *start,const int *end)
{
    int length = end - start;
    for (int i = 0; i < length; ++i)
    {
        cout << "2: " << *(start + i) << endl;
    }
}

void print(const int array[],size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "3: " << array[i] << endl;
    }
}