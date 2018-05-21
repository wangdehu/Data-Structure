//求一个矩阵中的马鞍点。如果矩阵A中存在这样的一个元素
//满足条件：A[i][j] 是第i行中值最小的元素，并且是第j列中值最大的元素，则称之位该矩阵的一个马鞍点。
//设计一个程序，求矩阵中所有的马鞍点。
#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
int a[4][4] = {
    {1, 0, 3, 4},
    {0, -11, 0, 0},
    {0, -22, 1, 0},
    {0, -33, 1, 1}

};
int n, m;
void init()
{
    n = 4, m = 4;
}
struct point
{
    int x, y;
};
void output(int x, int y)
{
    cout << x << "," << y << " is a point" << endl;
}
int main()
{
    init();
    int *mixs = new int[m];
    for (int i = 0; i < n; ++i)
    {
        int mix = inf, mix_j = -1;
        for (int j = 0; j < m; ++j)
        {
            // cout << a[i][j] << endl;
            if (a[i][j] < mix)
            {
                mix = a[i][j];
                mix_j = j;
            }
            mixs[i] = mix_j;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << mixs[i] << "   ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        int id = mixs[i];
        bool flag = true;
        for (int k = 0; k < m; ++k)
        {
            if (a[i][k] == a[i][id])
            {
                int idx = k;
                for (int j = 0; j < n; ++j)
                {
                    if (a[i][idx] < a[j][idx])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    output(i, idx);
            }
        }
    }
}