// 题目二：编写一个程序，实现单链表的各种基本运算，并在此基础上设计一个主程序完成如下功能：
// （1）初始化单链表H。
// （2）依次采用尾插法插入a,b,c,d,e元素。
// （3）输出单链表H及H的长度。
// （4）判断单链表H是否为空。
// （5）输出单链表H的第3个元素。
// （6）输出元素d的位置。
// （7）在第4个元素位置上插入f元素。
// （8）输出单链表L。
// （9）释放单链表L。
#include <iostream>
#include "List.h"
int main()
{
    std::cout << "please input some integer, if you input -1 ,it will be end!" << std::endl;
    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
    List<int> *l = new List<int>;
    l->Input_End(-1);
    l->Output();
    std::cout << "list's length is " << l->Length() << std::endl;
    if (l->IsEmpty())
    {
        std::cout << "this list is empty!!" << std::endl;
    }
    else
    {
        std::cout << "this list is not empty !!" << std::endl;
    }
    int temp;
    l->getData(3, temp);
    std::cout << "list's #3 is " << temp << std::endl;
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
    l->~List();
}
