// 题目一：编写一个程序，实现顺序栈的各种基本运算，并在此基础上设计一个主程序完成如下功能：
// （1）	初始化栈S。
// （2）	判断栈S是否非空。
// （3）	依次进栈元素a,b,c,d,e 。
// （4）	输出栈的长度。
// （5）	输出从栈顶到栈底的元素。
// （6）	输出出栈序列。
// （7）	释放栈。

#include <iostream>
#include "SeqStack.h"
int main()
{
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    //(1)
    SeqStack<int> S;
    //(2)
    if (S.IsEmpty())
    {
        std::cout << "S is empty" << std::endl;
    }
    else
    {
        std::cout << "S isn't  empty" << std::endl;
    }
    //(3)
    S.Push(a);
    S.Push(b);
    S.Push(c);
    S.Push(d);
    S.Push(e);
    //(4)
    std::cout << "S's length is " << S.getSize() << std::endl;
    //(5)
    // std::cout << S << std::endl;
    //(6)
    std::cout << "S will be all pop" << std::endl;

    while (!S.IsEmpty())
    {
        int tmp;
        S.Pop(tmp);
        std::cout << " " << tmp;
    }
    std::cout << std::endl;
    //(7)
    S.~SeqStack();
}