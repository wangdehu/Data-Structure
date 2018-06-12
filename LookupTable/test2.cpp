// 题目二：编写一个程序，输出在顺序表｛1,2,3,4,5,6,7,8,9,10｝中采用折半查找方法查找关键字5的过程。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main()
{
    int n = 10;
    int key = 3;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (a[mid] == key)
        {
            cout << "find " << key << " and its pos is " << mid;
            return 0;
        }
        cout << "a[" << mid + 1 << "] is  " << a[mid] << " !=  " << key << endl;

        if (a[mid] < key)
            left = mid + 1;
        if (a[mid] > key)
            right = mid - 1;
    }
    cout << " can't  find it" << endl;
}
