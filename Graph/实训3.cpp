//按Dijkstra算法计算得到从顶点A到其他各个定点的最短路径和最短路径长度
// 5 7
// 0 1 10
// 0 2 18
// 2 1 5
// 1 3 5
// 3 2 2
// 3 4 2
// 4 2 2

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
int mp[maxn][maxn], dis[maxn], path[maxn]; //path数组用于记录路径

void dijkstra(int sec, int n)
{
    int min, min_i;
    int vis[maxn] = {0};
    for (int i = 0; i < n; i++)
    {
        dis[i] = mp[sec][i];
    }
    vis[sec] = 1;
    dis[sec] = 0;
    for (int i = 1; i < n; i++)
    {
        min = inf;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] < min)
            {
                min = dis[j];
                min_i = j;
            }
        }
        vis[min_i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (dis[j] > min + mp[min_i][j])
            {
                path[j] = min_i;
                dis[j] = min + mp[min_i][j];
            }
        }
    }
}
void print(int sec, int n)
{
    stack<int> q;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (path[j] != -1)
        {
            q.push(j);
            j = path[j];
        }
        q.push(j);
        cout << sec << "->" << i << ",length==" << dis[i] << ",path: " << sec;
        while (!q.empty())
        {
            cout << "  " << q.top();
            q.pop();
        }
        printf("\n");
    }
}
int main()
{
    memset(mp, inf, sizeof mp);
    memset(path, -1, sizeof(path));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        mp[i][i] = 0;
    }

    for (int i = 0; i < m; ++i)
    {
        int tmpa, tmpb, tmpc;
        cin >> tmpa >> tmpb >> tmpc;
        mp[tmpa][tmpb] = tmpc;
    }
    dijkstra(0, n);
    print(0, n);
    return 0;
}
