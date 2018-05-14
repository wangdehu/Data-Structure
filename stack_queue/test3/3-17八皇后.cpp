#include <iostream>
#include <cstring>
using namespace std;
int mp[10][10];
int num = 1;
int n = 8;
bool cango(int x, int y)
{
    for (int i = 1; i <= n; ++i)
    {
        if (mp[x][i] == 1)
            return false;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (mp[i][y] == 1)
            return false;
    }
    int _x = x, _y = y;
    for (int i = 0; i + x <= n && i + y <= n; ++i)
    {
        if (mp[i + x][i + y])
        {
            return false;
        }
    }
    for (int i = 0; x - i >= 1 && y - i >= 1; ++i)
    {
        if (mp[x - i][y - i])
        {
            return false;
        }
    }
    for (int i = 0; x + i <= n && y - i >= 1; ++i)
    {
        if (mp[x + i][y - i])
        {
            return false;
        }
    }
    for (int i = 0; x - i >= 1 && y + i <= n; ++i)
    {
        if (mp[x - i][y + i])
        {
            return false;
        }
    }
    return true;
}
void f(int cnt)
{
    if (cnt == n + 1)
    {
        cout << num++ << ":" << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cout << mp[i][j];
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= n; ++i)
    {

        if (cango(cnt, i))
        {
            mp[cnt][i] = 1;
            f(cnt + 1);
            mp[cnt][i] = 0;
        }
    }
}
int main()
{
    memset(mp, 0, sizeof mp);
    f(1);
    return 0;
}