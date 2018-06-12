// 题目三：编写一个程序实现快速排序算法，用相关数据进行测试，并输出各次划分的结果。
#include <bits/stdc++.h>
using namespace std;
void printR(int r[], int maxn);
void QuickSort(int r[], int bot, int top);
int OnceQuickSort(int r[], int bot, int top);
int cmpnum = 0, movenum = 0;
const int maxn = 11;

int main()
{
    int r[maxn], b[maxn];
    srand(time(NULL));
    for (int i = 1; i < maxn; i++)
    {
        r[i] = rand() % 1000;
    }
    printR(r, maxn);
    int bot = 1;
    int top = maxn - 1;
    cout << "Quick Sorted:" << endl;
    QuickSort(r, bot, top);
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
void QuickSort(int r[], int bot, int top)
{
    if (bot < top)
    {
        int pivot = OnceQuickSort(r, bot, top);
        QuickSort(r, bot, pivot - 1);
        QuickSort(r, pivot + 1, top);
    }
}
int OnceQuickSort(int r[], int bot, int top)
{
    r[0] = r[bot];
    movenum++;
    while (bot < top)
    {
        while (r[top] >= r[0] && top > bot)
        {
            cmpnum++;
            top--;
        }
        swap(r[top], r[bot]);
        movenum += 3;
        while (r[bot] <= r[0] && top > bot)
        {
            bot++;
            cmpnum++;
        }
        swap(r[bot], r[top]);
        movenum += 3;
    }
    return bot;
}
