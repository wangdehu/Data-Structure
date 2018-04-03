// 题目三：编写一个程序，实现双链表的各种基本运算，并在此基础上设计一个主程序完成如下功能：（题目三、四选做1个）
// （1）初始化双链表H。
// （2）依次采用尾插法插入a,b,c,d,e元素。
// （3）输出双链表H及H的长度。
// （4）判断双链表H是否为空。
// （5）输出双链表H的第3个元素。
// （6）输出元素d的位置。
// （7）在第4个元素位置上插入f元素。
// （8）删除H的第3个元素。
// （9）输出双链表L。
// （10）释放双链表L。
#include <iostream>
#include "DblList.h"
int main()
{
    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
    DblList<int> *l = new DblList<int>;
    l->Input_End(-1);
    l->Output();
    std::cout << "DblList's length is " << l->Length() << std::endl;
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
    std::cout << "DblList's #3 is " << temp << std::endl;
    DblNode<int> *temp2 = l->Search(d);
    if (temp2 == nullptr)
    {
        std::cout << "the " << d << " not found!" << std::endl;
    }
    else
    {
        std::cout << "the " << d << "'s pos is " << temp2->data << std::endl;
    }
    l->Insert(4, f);
    l->Output();
    l->Remove(3, temp);
    l->Output();
    l->~DblList();
}
