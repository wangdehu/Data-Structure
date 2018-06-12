// 题目一：编写一个程序，实现图的相关运算，并在此基础上设计一个主程序完成如下功能：
// （1）	建立图（二）所示的有向图G的邻接矩阵，并输出之。
// （2）	由有向图G的邻接矩阵产生邻接表，并输出之。
// （3）	再由（2）的邻接表产生对应的邻接矩阵，并输出之。

// 6 10
// 0 1 3
// 0 2 1
// 1 3 5
// 3 4 4
// 4 1 8
// 4 0 9
// 5 4 5
// 1 5 7
// 5 0 6
// 2 5 5
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
int mp1[maxn][maxn], mp2[maxn][maxn];
struct node
{
    int to, value;
    node() {}
    node(int to, int value) : to(to), value(value) {}
};
struct Graph
{
    vector<node> link;
} pm[maxn];
int main(void)
{
    memset(mp1, 0, sizeof mp1);
    int n, m;
    cin >> n >> m;
    // cout << "create  Adjacency matrix :" << endl;
    for (int i = 0; i < m; ++i)
    {
        int tmpa, tmpb, tempc;
        cin >> tmpa >> tmpb >> tempc;
        mp1[tmpa][tmpb] = tempc;
    }
    // cout << "output  Adjacency matrix " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << mp1[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mp1[i][j])
            {
                pm[i].link.push_back(node(j, mp1[i][j]));
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (pm[i].link.empty() == false)
        {
            cout << i << ":";
            for (int j = 0; j < pm[i].link.size(); ++j)
            {
                cout << pm[i].link[j].to << "(" << pm[i].link[j].value << ")  ";
                mp2[i][pm[i].link[j].to] = pm[i].link[j].value;
            }
            cout << endl;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << mp2[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
