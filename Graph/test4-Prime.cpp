// 题目四：编写一个算法，实现求带权连通图中最小生成树的Prim算法（必做）和Kruskal算法（选做），对于如图三所示的带权连通图，输出从顶点V1出发的一棵最小生成树。

#include <iostream>
#include <cstring>
using namespace std;
int ad[2000][2000];
const int maxn = 999999999;
int n;
int prim()
{
    int sum = 0, min_id;
    int shortest[n + 1];
    for (int i = 1; i <= n; i++)
        shortest[i] = ad[1][i];
    for (int i = 1; i < n; i++)
    {
        int minx = maxn;
        min_id = -1;
        for (int j = 1; j <= n; j++)
        {
            if (shortest[j] < minx && shortest[j] != 0)
            {
                minx = shortest[j];
                min_id = j;
            }
        }
        if (min_id != -1)
        {
            sum += minx;
            shortest[min_id] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (ad[min_id][j] < shortest[j])
                    shortest[j] = ad[min_id][j];
            }
        }
        else
            return -1;
    }
    return sum;
}

int main()
{
    int m, a, b, c;
    while (cin >> m >> n && m)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                ad[i][j] = maxn;
            ad[i][i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            if (c < ad[a][b])
                ad[a][b] = ad[b][a] = c;
        }
        if (prim() == -1)
            cout << "?\n";
        else
            cout << prim() << endl;
    }
    return 0;
}