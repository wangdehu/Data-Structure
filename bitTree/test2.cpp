#include <bits/stdc++.h>
#include "binaryTree.h"
using namespace std;
template <class T>
binaryTreeNode<T> *createByPreAndIn(T *r1, T *r2, int n)
{
    if (n == 0)
    {
        return nullptr;
    }
    int k = 0;
    while (r1[0] != r2[k])
        k++;
    binaryTreeNode<T> *t = new binaryTreeNode<T>(r1[0]);
    t->lchild = createByPreAndIn(r1 + 1, r2, k);
    t->rchild = createByPreAndIn(r1 + k + 1, r2 + k + 1, n - k - 1);
    return t;
}
int main()
{

    char r1[30];
    char r2[30];
    cin >> r1 >> r2;
    int len = strlen(r1);
    binaryTreeNode<char> *node = createByPreAndIn(r1, r2, len);
    binaryTree<char> Tree(node);

    Tree.preOrder();
    cout << endl;
    Tree.inOrder();
    cout << endl;
    Tree.postOrder();
}