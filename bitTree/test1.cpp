//（1）	由如图一所示的二叉树创建其对应的二叉链表存储结构（提示：由二叉树的扩展前序序列构造二叉链表）
// （2）	输出二叉树的中序、先序、后序遍历序列的递归和非递归算法（中序必做，先序和后序选做）；
// （3）	输出二叉树B（树形结构或者广义表形式）；（选做）
// （4）	输出二叉树中指定结点值（假设所有节点值不同）的左右孩子结点；
// （5）	输出二叉树B的叶子结点个数；
// （6）	输出该二叉树的高度；
// （7）	输出二叉树中指定结点值（假设所有节点值不同）的结点所在的层次；（选做）
// （8）	释放二叉树B。
//ABC..E..DFY...G..
#include <bits/stdc++.h>
#include "binaryTree.h"
using namespace std;
int main()
{
    // ios::sync_with_stdio(0);
    binaryTree<char> Tree('.');
    Tree.CreateTree();

    // Tree.postOrder();
    // cout << endl;
    // binaryTree<int> Tree(-1);
    // Tree.CreateTree();
    // cout << "ok!" << endl;
    Tree.Gout(Tree.getRoot());
    cout << endl;
    // int tmp = Tree.sizes(Tree.getRoot());
    // cout << tmp << endl;
    // int tmp2 = Tree.height(Tree.getRoot());
    // cout << tmp2 << endl;
    // char c = '4';
    // int tmp3 = Tree.getHeightByItem(c, Tree.getRoot());
    // cout << tmp3 << endl;
    // binaryTreeNode<char> *tmp4 = Tree.Find(c, Tree.getRoot());
    // if (tmp4->lchild != nullptr)
    // {
    //     cout << "l " << tmp4->lchild->data << endl;
    // }
    // if (tmp4->rchild != nullptr)
    // {
    //     cout << "r " << tmp4->rchild->data << endl;
    // }
    // Tree.preOrder();
    // cout << endl;
    // Tree.inOrder();
    // cout << endl;
    // Tree.postOrder();
    // cout << endl;
    // Tree.preOrder2(Tree.getRoot());
    // cout << endl;
    // Tree.inOrder2(Tree.getRoot());
}