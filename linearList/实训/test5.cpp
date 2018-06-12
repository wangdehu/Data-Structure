//5.约瑟夫环
#include <iostream>
#include "CircList.h"
using namespace std;
int main()
{
    CircList<int> *l = new CircList<int>;
    int n, m, s;
    cout << "please input n,m,s" << endl;
    cin >> n >> m >> s;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        l->Insert(cnt++, i);
    }
    CircLinkNode<int> *pre = l->getHead();
    CircLinkNode<int> *first = l->getHead();
    while (m--)
    {
        int tmp = s;
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