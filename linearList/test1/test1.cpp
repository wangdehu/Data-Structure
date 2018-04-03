// 题目一：编写一个程序，实现顺序表的各种基本运算，并在此基础上设计一个主程序完成如下功能：
// （1）初始化顺序表L。
// （2）依次采用尾插法插入a,b,c,d,e元素。
// （3）输出顺序表L及L的长度。
// （4）判断顺序表L是否为空。
// （5）输出顺序表L的第3个元素。
// （6）输出元素d的位置。
// （7）在第4个元素位置上插入f元素。
// （8）删除L的第3个元素。
// （9）输出顺序表L。
// （10）释放顺序表L。
#include <iostream>
#include "SeqList.h"
int main()
{
    int a = 1, b = 5, c = 3, d = 2, e = 4;
    SeqList<int> *MyList = new SeqList<int>;

    MyList->Input_End();

    MyList->Output();
    std::cout << std::endl;
    int temp;
    MyList->getData(3, temp);
    std::cout << "   #3: " << temp << std::endl;

    std::cout << d << " 's pos is " << MyList->Search(d) << std::endl;
    MyList->Insert(4, e);
    MyList->Output();
    MyList->Remove(3, temp);
    MyList->Output();
    MyList->~SeqList();
    return 0;
}
