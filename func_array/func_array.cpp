#include <iostream>
#include <string>
using namespace std;
int sum_arr(const int arr[],int length);
void fill_arr(int arr[],int n);
void main()
{
    // const int size = 6;
    // int student[size] = {150,150,150,100,100,100};
    // int total = sum_arr(student,size);
    // cout << "total: " << total << endl;
    // cin.get();
    const int size = 6;
    int arr[size];
    fill_arr(arr,size);
    cout << "scores: " <<endl;
    for (const int i : arr)
    {
        cout << i <<endl;
    }
}
int sum_arr(const int arr[], const int length)
{
    int sum = 0;
    for (int i = 0; i < length; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

void fill_arr(int arr[],int n)
{
    cout << "please enter scores(chinese/math/english/physics/chemistry/biology): " << endl;
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        arr[i] = temp;
    }
}
