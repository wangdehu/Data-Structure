//用单链表表示的两个集合（假设同一个集合中不存在重复的元素）
//求它们的并、交和差运算。
// 将单链表按某个基准划分。编写一个程序，以给定值x为基准将单链表分割为两部分，
//所有小于x的结点排在大于或等于x的结点之前。并分析时间复杂度。
#include <iostream>
#include "List.h"
using namespace std;
template <class T>
List<T> *Or(List<T> *t1, List<T> *t2)
{
    List<int> *res = new List<int>;
    int cnt1 = t1->Length();
    int cnt2 = t2->Length();

    int cnt = 0;
    for (int i = 1; i <= cnt1; ++i)
    {
        res->Insert(cnt++, t1->Locate(i)->data);
    }
    for (int i = 1; i <= cnt2; ++i)
    {
        T tmp = t2->Locate(i)->data;
        int fid = res->Search(tmp);
        if (fid == -1)
        {
            res->Insert(cnt++, tmp);
        }
    }
    return res;
}
template <class T>
List<T> *And(List<T> *t1, List<T> *t2)
{
    List<int> *res = new List<int>;
    int cnt1 = t1->Length();
    int cnt2 = t2->Length();

    int cnt = 0;
    for (int i = 1; i <= cnt2; ++i)
    {
        T tmp = t2->Locate(i)->data;
        int fid = t1->Search(tmp);
        if (fid != -1)
        {
            res->Insert(cnt++, tmp);
        }
    }
    return res;
}
template <class T>
List<T> *Sub(List<T> *t1, List<T> *t2)
{
    List<int> *res = new List<int>;
    int cnt1 = t1->Length();

    int cnt = 0;
    for (int i = 1; i <= cnt1; ++i)
    {
        T tmp = t1->Locate(i)->data;
        int fid = t2->Search(tmp);
        if (fid == -1)
        {
            res->Insert(cnt++, tmp);
        }
    }
    return res;
}
int main()
{
    List<int> *l1 = new List<int>;
    List<int> *l2 = new List<int>;
    int cnt1 = 0, cnt2 = 0;

    l1->Insert(cnt1++, 1);
    l1->Insert(cnt1++, 3);
    l1->Insert(cnt1++, 4);
    l1->Insert(cnt1++, 7);
    l1->Insert(cnt1++, 9);

    l2->Insert(cnt2++, 1);
    l2->Insert(cnt2++, 2);
    l2->Insert(cnt2++, 7);
    l2->Insert(cnt2++, 5);

    cout << "l1 or l2:" << endl;
    List<int> *l3 = Or(l1, l2);
    l3->Output();
    delete l3;

    cout << "l1 and l2:" << endl;
    List<int> *l4 = And(l1, l2);
    l4->Output();
    delete l4;

    cout << "l1 sub l2:" << endl;
    List<int> *l5 = Sub(l1, l2);
    l5->Output();
    delete l5;

    cout << "l2 sub l1:" << endl;
    List<int> *l6 = Sub(l2, l1);
    l6->Output();
    delete l6;
}