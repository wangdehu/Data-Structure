// 题目四：编写一个程序，实现循环单链表的各种基本运算，并在此基础上设计一个主程序完成如下功能：
// （1）初始化循环单链表H。
// （2）依次采用尾插法插入a,b,c,d,e元素。
// （3）输出循环单链表H及H的长度。
// （4）判断循环单链表H是否为空。
// （5）输出循环单链表H的第3个元素。
// （6）输出元素d的位置。
// （7）在第4个元素位置上插入f元素。
// （8）删除H的第3个元素。
// （9）输出循环单链表L。
// （10）释放循环单链表L。
#include <iostream>
#include "CircList.h"
int main()
{
    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6000;
    CircList<int> *l = new CircList<int>;
    l->Input_End(-1);
    l->Output();

    std::cout << "CircList's length is " << l->Length() << std::endl;
    if (l->IsEmpty())
    {
        std::cout << "DblList is empty!" << std::endl;
    }
    else
    {
        std::cout << "DblList is not empty!" << std::endl;
    }
    int temp;
    l->getData(3, temp);
    std::cout << "CircList's #3 is " << temp << std::endl;

    int temp2 = l->Search(d);
    if (temp2 == -1)
    {
        std::cout << "the " << d << " not found!" << std::endl;
    }
    else
    {
        std::cout << "the " << d << "'s pos is " << temp2 << std::endl;
    }

    if (l->Length() >= 3)
    {
        std::cout << "insert a value " << f << " in 4 pos !" << std::endl;
        l->Insert(3, f);
        l->Output();
    }
    if (l->Length() >= 3)
    {
        std::cout << "remove pos 3 's  value " << std::endl;
        l->Remove(3, f);
        l->Output();
    }
    l->~CircList();
}
