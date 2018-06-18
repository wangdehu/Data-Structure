//  用单链表实现两个大整数相加运算。要求：（选做）
// （1）	将用户输入的十进制整数字符串转化为带头结点的单链表，每个结点存放一个整数位。
// （2）	求两个整数单链表相加的结果单链表
// （3）	求结果单链表的中间位，如234的中间位是“3”，2345的中间位是“3”。

#include <bits/stdc++.h>
#include "List.h"
using namespace std;
int outputMid(List<int> *t)
{
    int posc = (t->Length() + 1) / 2;
    return t->Locate(posc)->data;
}
List<int> *add(List<int> *Ba, List<int> *Bb)
{
    LinkNode<int> *Nodea = Ba->getHead();
    LinkNode<int> *Nodeb = Bb->getHead();
    List<int> *Bc = new List<int>;
    bool flag = false;
    while (Nodea->link != nullptr && Nodeb->link != nullptr)
    {
        int ta = Nodea->link->data;
        int tb = Nodeb->link->data;
        if (flag)
            ta++;
        if (ta + tb >= 10)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        Bc->Insert(0, (ta + tb) % 10);
        Nodea = Nodea->link;
        Nodeb = Nodeb->link;
    }
    while (Nodea->link != nullptr)
    {
        int temp = Nodea->link->data;
        if (flag)
            temp++;
        if (temp >= 10)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        Bc->Insert(0, temp % 10);
        Nodea = Nodea->link;
    }
    while (Nodeb->link != nullptr)
    {
        int temp = Nodeb->link->data;
        if (flag)
            temp++;
        if (temp >= 10)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        Bc->Insert(0, temp % 10);
        Nodeb = Nodeb->link;
    }
}
List<int> *getList(string str)
{
    List<int> *B = new List<int>;
    int lena = str.size();
    for (int i = 0; i < lena; ++i)
    {
        int temp = str[i] - '0';
        B->Insert(0, temp);
    }
    return B;
}
int main()
{
    cout << "please input integer a,b" << endl;
    string a, b;
    cin >> a >> b;
    List<int> *Ba = getList(a);
    List<int> *Bb = getList(b);
    cout << "a's output:" << endl;
    Ba->Output();
    cout << "b's output:" << endl;
    Bb->Output();
    List<int> *Bc = add(Ba, Bb);
    cout << "c's output:" << endl;
    Bc->Output();
    cout << "the c's midpos is " << outputMid(Bc);

    delete Ba, Bb, Bc;

    return 0;
}