// 借助栈实现单链表上的逆置运算
#include <iostream>
#include "simpleList.h"
using namespace std;

int main()
{
    List<int> L;
    L.Input_End(-1);
    L.Output();
    cout << endl;
    L.reverse();
    L.Output();
}