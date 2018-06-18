// 题目四：编写一个算法，实现求带权连通图中最小生成树的Prim算法（必做）和Kruskal算法（选做），对于如图三所示的带权连通图，输出从顶点V1出发的一棵最小生成树。

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
int n, m;
struct edge
{
    int v, u, w;
    edge(int v, int u, int w) : v(v), u(u), w(w) {}
    bool operator<(const edge f) const
    {
        if (w < f.w)
            return true;
        return false;
    }
};
vector<edge> edges;
int r[MAXN];
int find(int i)
{
    return r[i] == i ? i : r[i] = find(r[i]);
}
int CheckSector()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (r[i] == i)
            cnt++;
    }
    return cnt;
}
int slove()
{
    int sum = 0;
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= m; i++)
    {
        int x = find(edges[i].v), y = find(edges[i].u);
        if (x != y)
        {
            sum += edges[i].w;
            r[y] = x;
        }
    }
    if (CheckSector() == 1)
        return sum;
    return -1;
}
int main()
{
    int a, b, c;
    while (scanf("%d%d", &m, &n), m)
    {
        edges.clear();
        edges.push_back(edge(0, 0, 0));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back(edge(a, b, c));
        }
        for (int i = 1; i <= n; i++)
            r[i] = i;
        int sum = slove();
        if (sum == -1)
            printf("?\n");
        else
            printf("%d\n", sum);
    }
}