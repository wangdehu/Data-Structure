//       0123456
//      0xxxxxxx
//      1x10000x
//      2x0xx0xx
//      3x0x000x
//      4x000x0x
//      5x0xx02x
//      6xxxxxxx
//	用栈求解下图所示迷宫的所有路径，并输出最短路径长度及该最短路径。
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> point;
const int inf = 0x3f3f3f3f;
int mp[10][10]{
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1},
};
int maxn = inf;
stack<point> s1;
stack<int> s2;
bool vis[100][100] = {0};
vector<point> v1;
vector<point> v2;
int dx[5] = {0, 1, -1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};

int main()
{
    int first_x = 1, first_y = 1;
    int second_x = 5, second_y = 5;
    s1.push(point(first_x, first_y));
    s2.push(0);
    v1.push_back(point(second_x, second_y));
    bool flag = false;
    while (!s1.empty())
    {
        auto x = s1.top();
        if (x.first == second_x && x.second == second_y)
        {
            if (maxn > v1.size())
            {
                maxn = v1.size();
                v2 = v1;
            }
            for (auto &y : v1)
            {
                cout << "(" << y.first << "," << y.second << ")" << (y == (v1[v1.size() - 1]) ? "\n" : "->");
            }
            s1.pop();
            s2.pop();
            v1.pop_back();
            cout << endl;
            continue;
        }
        vis[s1.top().first][s1.top().second] = 1;
        int pos = s2.top();
        for (int i = pos + 1; i < 5; ++i)
        {
            int x = s1.top().first + dx[i];
            int y = s1.top().second + dy[i];
            if (!mp[x][y] && !vis[x][y])
            {
                v1.push_back(point(x, y));
                s2.pop();
                s2.push(i);
                s2.push(0);
                s1.push(point(x, y));
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            vis[s1.top().first][s1.top().second] = 0;
            s1.pop();
            s2.pop();
            v1.pop_back();
        }
        else
        {
            flag = false;
        }
    }
    cout << "Short road:" << maxn << endl;
    for (auto &y : v2)
    {
        cout << "(" << y.first << "," << y.second << ")" << (y == (v2[v2.size() - 1]) ? "\n" : "->");
    }
    return 0;
}