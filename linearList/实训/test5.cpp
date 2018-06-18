//5.约瑟夫环
// n为个数 m为报数间隔
#include <iostream>
#include "CircList.h"
using namespace std;
int main()
{
    CircList<int> *l = new CircList<int>;
    int n, m, s;
    cout << "please input n,m" << endl;
    cin >> n >> m;
    int cnt = 0;
    for (int i = n; i >= 1; --i)
    {
        l->Insert(0, i);
    }
    CircLinkNode<int> *pre = l->getHead();
    CircLinkNode<int> *first = l->getHead();
    for (int i = 0; i < n - 1; ++i)
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
}