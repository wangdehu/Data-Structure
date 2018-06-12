//题目四：编写一个程序实现堆排序算法，用相关数据进行测试，并输出各趟划分的排序结果。
#include <bits/stdc++.h>
using namespace std;
void printR(int r[], int maxn);
void fixdown(int r[], int i, int n);
void makeminheap(int r[], int n);
int cmpnum = 0, movenum = 0;
int main()
{
    const int maxn = 51;
    int r[maxn], b[maxn];
    srand(time(NULL));
    for (int i = 1; i <= 50; i++)
    {
        r[i] = rand() % 1000;
    }
    printR(r, maxn);
    cout << "Heap Sorted:" << endl;
    makeminheap(r, maxn);
    for (int i = maxn - 1; i > 0; i--)
    {
        swap(r[i], r[1]);
        movenum += 3;
        makeminheap(r, i);
    }
    printR(r, maxn);
    cout << "Actual number of comparisons:" << cmpnum << endl;
    cout << "Actual number of movements:" << movenum << endl;
    return 0;
}
void printR(int r[], int maxn)
{
    for (int i = 1; i < maxn; i++)
    {
        cout << setw(5) << r[i] << " ";
        if (i % 10 == 0)
        {
            cout << endl;
        }
    }
}
void fixdown(int r[], int i, int n)
{
    int j;
    r[0] = r[i];
    movenum++;
    j = 2 * i;
    while (j < n)
    {
        cmpnum++;
        if (j + 1 < n && r[j + 1] > r[j])
        {
            j++;
        }
        cmpnum++;
        if (r[j] <= r[0])
        {
            break;
        }
        r[i] = r[j];
        movenum++;
        i = j;
        j = 2 * i;
    }
    r[i] = r[0];
    movenum++;
}
void makeminheap(int r[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        fixdown(r, i, n);
    }
}
