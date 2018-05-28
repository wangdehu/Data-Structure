#include <bits/stdc++.h>
#include "binaryTree.h"
using namespace std;
int main()
{
    // ios::sync_with_stdio(0);
    binaryTree<char> Tree('.');
    Tree.CreateTree();

    // cout << "ok!" << endl;

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