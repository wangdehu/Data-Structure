// 题目一：编写一个程序，输出在顺序表｛3,6,2,10,1,8,5,7,4,9｝中采用顺序方法查找关键字5的过程。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int main(void)
{
    int n = 10;
    int key = 5;
    int a[10] = {3, 6, 2, 10, 1, 8, 5, 7, 4, 9};
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == key)
        {
            cout << "a[" << i + 1 << "] == " << key << endl;
            return 0;
        }
        else
        {
            cout << "a[" << i + 1 << "] is  " << a[i] << " !=  " << key << endl;
        }
    }
    cout << " can't  find it" << endl;
}