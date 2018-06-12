//编写一个递归算法，输出自然数1-n的全排列
#include <iostream>
#include <algorithm>
using namespace std;
const int arraySize = 105;
int array[arraySize];
int n;
void dfs(int m)
{
    if (m == n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << array[i];
        }
        cout << endl;
        return;
    }

    for (int i = m; i <= n; i++)
    {
        swap(array[i], array[m]);
        dfs(m + 1);
        swap(array[i], array[m]);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        array[i] = i;
    }
    dfs(1);
    return 0;
}