//3.实现稀疏矩阵的基本运算。假设n*n的稀疏矩阵A采用三元组表示，设计一个程序，实现如下功能：
//（1）	生成如下两个稀疏矩阵的三元组a和b；
//（2）	输出a转置矩阵的三元组
//（3）	输出a+b的三元组
// [1	0	3	0 ]             [3	 0  0	0]
// [0	1	0	0 ]             [0	 4  0	0]
// [0	0	1	0 ]             [0	 0  1	0]
// [0   0	1	1 ]             [0	 0 	0	2]

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y, v;
    node(int x, int y, int v) : x(x), y(y), v(v) {}
};
struct Matrix
{
    vector<node> v;
    int n, m;
} va, vb;
const int am = 4, an = 4, bm = 4, bn = 4;
int a[4][4] = {
    {1, 0, 3, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1}

};
int b[4][4] = {
    {3, 0, 0, 0},
    {0, 4, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 2}

};
void init()
{
    va.m = am;
    va.n = an;

    for (int i = 0; i < an; ++i)
    {
        for (int j = 0; j < am; ++j)
        {
            if (a[i][j])
            {
                va.v.push_back(node(i, j, a[i][j]));
            }
        }
    }
    vb.m = bm;
    vb.n = bn;
    for (int i = 0; i < bn; ++i)
    {
        for (int j = 0; j < bm; ++j)
        {
            if (b[i][j])
            {
                vb.v.push_back(node(i, j, b[i][j]));
            }
        }
    }
}
void output(Matrix *t)
{
    cout << "i      j     value" << endl;
    for (auto &i : t->v)
    {
        cout << i.x << "   " << i.y << "   " << i.v << endl;
    }
    cout << endl;
}
Matrix reverse(Matrix *t)
{
    Matrix res;
    int *rowSize = new int[t->m];
    int *rowStart = new int[t->m];
    res.n = t->n;
    res.m = t->m;
    res.v = t->v;
    // cout << "xxx" << endl;

    for (int i = 0; i < t->m; ++i)
    {
        rowSize[i] = 0;
    }
    for (auto i : t->v)
    {
        // cout << "i.y==" << i.y << endl;
        rowSize[i.y]++;
    }

    rowStart[0] = 0;
    // cout << "xxxx" << endl;

    for (int i = 1; i < res.m; ++i)
    {
        rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
    }
    // cout << res.v.size() << endl;

    for (auto i : t->v)
    {
        int j = rowStart[i.y];
        // cout << "j==" << j << endl;

        res.v[j] = i;
        swap(res.v[j].x, res.v[j].y);
        rowStart[i.y]++;
    }
    // cout << res.v.size() << endl;
    delete[] rowSize;
    delete[] rowStart;
    // output(&res);

    return res;
}
Matrix *add(Matrix *t1, Matrix *t2)
{
    if (t1->n != t2->n || t1->m != t2->m)
    {
        return nullptr;
    }
    Matrix *ptr = new Matrix;
    ptr->m = t1->m;
    ptr->n = t1->n;
    int cnt1 = 0, cnt2 = 0;
    int num1 = t1->v.size();
    int num2 = t2->v.size();
    int cnt3 = 0;
    while (cnt1 < num1 && cnt2 < num2)
    {
        int idx_a = t1->v[cnt1].x * (t1->m) + t1->v[cnt1].y;
        int idx_b = t2->v[cnt2].x * (t2->m) + t2->v[cnt2].y;
        // cout << "idx==    " << idx_a << "   " << idx_b << endl;
        // cout << "cnt==   " << cnt1 << "    " << cnt2 << endl;
        if (idx_a < idx_b)
        {
            ptr->v.push_back(t1->v[cnt1]);
            cnt1++;
        }
        else if (idx_a > idx_b)
        {
            ptr->v.push_back(t2->v[cnt2]);
            cnt2++;
        }
        else
        {
            int total = t2->v[cnt2].v + t1->v[cnt1].v;
            if (total)
            {
                ptr->v.push_back(node(t1->v[cnt1].x, t1->v[cnt1].y, total));
            }
            cnt1++, cnt2++;
        }
    }
    for (; cnt1 < num1; ++cnt1)
    {
        ptr->v.push_back(t1->v[cnt1++]);
        // cout << "???" << endl;
    }
    for (; cnt2 < num2; ++cnt2)
    {
        ptr->v.push_back(t2->v[cnt2++]);
        // cout << "???2" << endl;
    }
    return ptr;
}

int main()
{
    init();
    // cout << "??" << endl;

    // output(&va);
    // output(&vb);
    // cout << "???" << endl;
    cout << "a's reverse is" << endl;
    Matrix r = reverse(&va);
    output(&r);

    Matrix *sum = add(&va, &vb);
    output(sum);
    delete sum;
    // cout << "????" << endl;

    return 0;
}
