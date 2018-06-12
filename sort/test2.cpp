// 题目二：编写一个程序实现希尔排序算法，并输出｛9,8,7,6,5,4,3,2,1,0｝的排序过程。
#include <bits/stdc++.h>
using namespace std;
void printR(int r[], int maxn);
void ShellSort(int r[], int maxnn);
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
    cout << "Shell sorted" << endl;
    ShellSort(r, maxn);
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
void ShellSort(int r[], int maxn)
{
    int i, j;
    for (maxn = maxn / 2; maxn >= 1; maxn /= 2)
    {
        for (i = 1 + maxn; i <= 50; i++)
        {
            r[0] = r[i];
            movenum++;
            for (j = i - maxn; j > 0 && r[j] > r[0]; j -= maxn)
            {
                cmpnum++;
                r[j + maxn] = r[j];
                movenum++;
            }
            r[j + maxn] = r[0];
            movenum++;
        }
    }
}
