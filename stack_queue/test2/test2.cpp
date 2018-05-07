// 题目二：编写一个程序，实现循环队列的各种基本运算，并在此基础上设计一个主程序完成如下功能：
// （1）	初始化队列Q。
// （2）	判断队列Q是否非空。
// （3）	依次进队列元素a,b,c。
// （4）	出队一个元素，输出该元素。
// （5）	输出队列Q的元素个数。
// （6）	依次进入队列元素d,e,f。
// （7）	输出出队序列。
// （8）	释放队列。
#include "SeqQueue.h"
#include <iostream>
int main()
{
    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
    //(1)
    SeqQueue<int> Q;
    //(2)
    if (Q.IsEmpty())
    {
        std::cout << "Q is empty" << std::endl;
    }
    else
    {
        std::cout << "Q isn't  empty" << std::endl;
    }
    //(3)
    Q.Push(a);
    Q.Push(b);
    Q.Push(c);
    //(4)
    int tmp = -1;
    Q.Pop(tmp);
    std::cout << "the front is " << tmp << ". it be pop" << std::endl;
    //(5)
    std::cout << "Q's length is " << Q.getSize() << std::endl;
    // std::cout << Q << std::endl;
    //(6)
    Q.Push(d);
    Q.Push(e);
    Q.Push(f);
    //(7)
    std::cout << "Q will be all pop" << std::endl;
    while (!Q.IsEmpty())
    {
        int tmp;
        Q.Pop(tmp);
        std::cout << " " << tmp;
    }
    std::cout << std::endl;
    //(8)
    Q.~SeqQueue();
}