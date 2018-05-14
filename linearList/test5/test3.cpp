//实现两个多项式相加运算。
#include <iostream>
#include "List.h"
using namespace std;
struct edge
{
    int c;
    int s;
    edge(int c, int s) : c(c), s(s) {}
    edge() {}
    friend bool operator==(edge a, edge b)
    {
        if (a.c == b.c && a.s == b.s)
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, edge &p)
    {
        // out < "dsadfa\n";
        out << p.c << " " << p.s << endl;
        return out;
    }
};

template <class T>
List<T> *getSum(List<T> *t1, List<T> *t2)
{
    List<edge> *res = new List<edge>;
    LinkNode<T> *one = t1->getHead()->link;
    LinkNode<T> *two = t2->getHead()->link;
    int cnt = 0;

    while (one != nullptr && two != nullptr)
    {
        if ((one->data.s) == (two->data.s))
        {
            int sum = (one->data.c) + (two->data.c);
            if (sum)
            {
                res->Insert(cnt++, edge(sum, (one->data.s)));
            }
            one = one->link;
            two = two->link;
        }
        else if ((one->data.s) < (two->data.s))
        {
            res->Insert(cnt++, edge((one->data.c), (one->data.s)));
            one = one->link;
        }
        else
        {
            res->Insert(cnt++, edge((two->data.c), (two->data.s)));
            two = two->link;
        }
    }
    while (one != nullptr)
    {
        res->Insert(cnt++, edge((one->data.c), (one->data.s)));
        one = one->link;
    }
    while (two != nullptr)
    {
        res->Insert(cnt++, edge((two->data.c), (two->data.s)));
        two = two->link;
    }
    return res;
}
int main()
{
    List<edge> *l1 = new List<edge>;
    List<edge> *l2 = new List<edge>;
    int cnt1 = 0, cnt2 = 0;
    int d1[7] = {1, 3, 0, 2, 22, 7, 0};
    int d2[7] = {1, 0, 2, 5, -4, -2, 1};
    for (int i = 0; i < 7; ++i)
    {
        if (d1[i])
        {
            l1->Insert(cnt1++, edge(d1[i], i));
        }
        if (d2[i])
        {
            l2->Insert(cnt2++, edge(d2[i], i));
        }
    }
    // l1->Output();
    // cout << endl;
    // l2->Output();
    // cout << endl;
    List<edge> *l3 = getSum(l1, l2);
    l3->Output();
    delete l3;
}