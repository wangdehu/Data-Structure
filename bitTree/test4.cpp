// 4.	线索化二叉树的操作：
// （1）	编写一个程序实现二叉树的中序线索化，采用递归和非递归方式输出中序线索二叉树的中序序列，并以图（一）所示的二叉树B对程序进行验证；
// （2）	求出该线索化二叉树中给定结点的直接前驱和直接后继结点。
// （3）	P249 选做 5.31。

#include <bits/stdc++.h>
#include "ThreadTree.h"
using namespace std;
int main()
{
    // ios::sync_with_stdio(0);
    ThreadTree<char> Tree('.');
    Tree.CreateTree();
    Tree.createinThread();
    Tree.inorderByThread();
}