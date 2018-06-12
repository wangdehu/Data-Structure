//
// 题目二：编写一个程序，实现图的遍历算法，并在此基础上设计一个主程序完成如下功能：
// （1）	输出图（二）的有向图G从顶点V1开始的深度优先遍历序列序列（递归算法）
// （2）	输出如图（二）的有向图G从顶点v1开始的深度优先遍历序列（非递归算法）
// （3）	输出如图（二）的有向图G从顶点v1开始的广度优先遍历序列
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
int n, m;
int vis[maxn];
int main(void)
{
    int num[maxn];
    cin >> n >> m;
    memset(vis, -1, sizeof vis);
    memset(num, 0, sizeof num);
    for (int i = 0; i < m; ++i)
    {
        int tmpa, tmpb, tempc;
        cin >> tmpa >> tmpb >> tempc;
        pm[tmpa].link.push_back(node(tmpb, tempc));
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < pm[i].link.size(); ++j)
        {
            num[pm[i].link[j].to]++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << i << "  " << num[i] << endl;
    }
}
