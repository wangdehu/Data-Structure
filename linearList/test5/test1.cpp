// 将单链表按某个基准划分。编写一个程序，以给定值x为基准将单链表分割为两部分，
//所有小于x的结点排在大于或等于x的结点之前。并分析时间复杂度。
#include <iostream>
#include "List.h"
using namespace std;
template <class T>
void listsort(List<T> *l, T tag)
{
    int len = l->Length();
    int cnt1 = 0, cnt2 = 0;
    List<T> *l1 = new List<T>;
    List<T> *l2 = new List<T>;
    for (int i = 1; i <= len; ++i)
    {
        T tmp = l->Locate(i)->data;
        if (tmp < tag)
        {
            bool ag = l1->Insert(cnt1++, tmp);
        }
        else
        {
            bool ag = l2->Insert(cnt2++, tmp);
        }
    }
    l->makeEmpty();
    int cnt = 0;
    for (int i = 1; i <= cnt1; ++i)
    {
        l->Insert(cnt++, l1->Locate(i)->data);
    }
    for (int i = 1; i <= cnt2; ++i)
    {
        l->Insert(cnt++, l2->Locate(i)->data);
    }
}
int main()
{
    cout << "please input some integer, if you input -1 ,it will be end!" << endl;
    List<int> *l = new List<int>;
    l->Input_End(-1);
    l->Output();
    cout << "please input a value, to slice list" << endl;
    int tag;
    cin >> tag;
    listsort(l, tag);
    cout << l->Length() << endl;
    l->Output();
}