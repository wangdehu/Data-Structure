// 题目四：编写一个程序，包含二叉排序树的创建、查找和删除算法，在此基础上编写程序，完成以下功能：
// （1）	由关键字序列（4，9，0，1，8，6，3，5，2，7）创建一棵二叉排序树bt并以括号表示法输出。
// （2）	判断bt是否为一棵二叉排序树
// （3）	采用递归或者非递归方法查找关键字为6的结点，并输出其查找路径；
// （4）	分别删除bt中的关键字4和5的结点，并输出删除后的二叉排序树。

#include <bits/stdc++.h>
#include "BinSortTree.h"
using namespace std;
int main()
{
    BinSortTree<int> a;
    a.insert(4);
    a.insert(9);
    a.insert(0);
    a.insert(1);
    a.insert(8);
    a.insert(6);
    a.insert(3);
    a.insert(5);
    a.insert(2);
    a.insert(7);

    a.inOrder();
    cout << endl;
    a.search_recursion(6);

    a.remove(4);
    a.remove(5);
    cout << endl;
    a.inOrder();
    return 0;
}