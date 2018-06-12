//已知A[n]为整数数组，试写出实现下列运算的递归算法
//(1)求数组A中的最大整数
//(2)求n个整数的和
//(3)求n个整数的平均值
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ctime>
using namespace std;
const int arraySize = 20;
int array[arraySize];
int n;
int getMax(int l, int r)
{
    if (l == r)
        return array[l];
    int mid = (l + r) >> 1;
    return max(getMax(l, mid), getMax(mid + 1, r));
}
int getSum(int l, int r)
{
    if (l == r)
        return array[l];
    int mid = (l + r) >> 1;
    return getSum(l, mid) + getSum(mid + 1, r);
}
double getAverage(int l, int r)
{
    double length = r - l + 1;
    if (l == r)
        return array[l];
    int mid = (l + r) >> 1;
    return (getAverage(l, mid) * (mid - l + 1) + getAverage(mid + 1, r) * (r - mid)) / length;
}
double getAverage2(int l, int r)
{
    double length = r - l + 1;
    return getSum(l, r) / length;
}
void init()
{
    srand(time(NULL));
    n = rand() % arraySize;
    if (n == 0)
    {
        n = arraySize;
    }
    for (int i = 0; i < n; ++i)
    {
        array[i] = rand() % 501;
    }
}
void print()
{
    cout << "n = " << n << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main()
{
    init();
    print();
    cout << "the max value is " << getMax(0, n - 1) << endl;
    cout << "the sum value is " << getSum(0, n - 1) << endl;
    cout << "the average value is " << fixed << setprecision(6) << getAverage(0, n - 1) << endl;
    cout << "the average2 value is " << fixed << setprecision(6) << getAverage2(0, n - 1) << endl;

    return 0;
}