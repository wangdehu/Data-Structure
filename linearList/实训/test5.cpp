//5.约瑟夫环
// n为个数 m为报数间隔
#include <iostream>
#include "CircList.h"
using namespace std;
void init(int n, CircList<int> *l)
{
    for (int i = n; i >= 1; --i)
    {
        l->Insert(0, i);
    }
}
void Popone(CircList<int> *l, int m, CircLinkNode<int> *&pre, CircLinkNode<int> *&first)
{
    int tmp = m;
    while (tmp--)
    {
        pre = pre->link;
        if (pre == first)
        {
            pre = pre->link;
        }
    }
    cout << pre->data << " be out " << endl;
    int uu;
    l->Remove(l->Search(pre->data), uu);
}
int main()
{
    CircList<int> *l = new CircList<int>;
    int n, m, s;
    cout << "please input n,m" << endl;
    cin >> n >> m;
    int cnt = 0;
    init(n, l);
    CircLinkNode<int> *pre = l->getHead();
    CircLinkNode<int> *first = l->getHead();
    for (int i = 0; i < n - 1; ++i)
    {
        Popone(l, m, pre, first);
    }
}