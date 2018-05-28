#include <iostream>
#include <algorithm>
#include <stack>
template <class T>
struct binaryTreeNode
{
    T data;
    binaryTreeNode<T> *lchild, *rchild;

    binaryTreeNode(T tmp) : data(tmp), lchild(nullptr), rchild(nullptr) {}
    binaryTreeNode() : lchild(nullptr), rchild(nullptr) {}
};
template <class T>
class binaryTree
{
  private:
    binaryTreeNode<T> *root;
    T endpos;

    void destroy(binaryTreeNode<T> *tmp);

    binaryTreeNode<T> *parent(binaryTreeNode<T> *start, binaryTreeNode<T> *tmp);

  public:
    binaryTree() : root(nullptr) {}
    binaryTree(T tmp) : root(nullptr), endpos(tmp) {}
    binaryTree(binaryTreeNode<T> *tmp) : root(tmp), endpos('.') {}

    ~binaryTree();

    bool Isempty();
    binaryTreeNode<T> *parent(binaryTreeNode<T> *tmp);
    binaryTreeNode<T> *lchi(binaryTreeNode<T> *tmp);
    binaryTreeNode<T> *rchi(binaryTreeNode<T> *tmp);
    int sizes(binaryTreeNode<T> *tmp);
    int height(binaryTreeNode<T> *tmp, int maxn = 1);
    // bool Insert(T item);
    // bool Remove(T item);
    binaryTreeNode<T> *Find(const T &item, binaryTreeNode<T> *tmp) const;
    // bool getData(const T &item) const;
    int getHeightByItem(const T &item, binaryTreeNode<T> *tmp, int height = 1);
    binaryTreeNode<T> *getRoot() const
    {
        return root;
    }
    void CreateTree();
    binaryTreeNode<T> *CreateTree(binaryTreeNode<T> *tree);
    void preOrder();
    void preOrder(binaryTreeNode<T> *tmp);
    void preOrder2(binaryTreeNode<T> *tmp);

    void inOrder();
    void inOrder(binaryTreeNode<T> *tmp);
    void inOrder2(binaryTreeNode<T> *tmp);

    void postOrder();
    void postOrder(binaryTreeNode<T> *tmp);
    void output(binaryTreeNode<T> *tmp);

    void Gout(binaryTreeNode<T> *tmp);
};
template <class T>
binaryTree<T>::~binaryTree()
{
    destroy(root);
}
template <class T>
void binaryTree<T>::destroy(binaryTreeNode<T> *tmp)
{
    if (tmp != nullptr)
    {
        destroy(tmp->lchild);
        destroy(tmp->rchild);
        delete tmp;
    }
}
template <class T>
bool binaryTree<T>::Isempty()
{
    return root == nullptr;
}
template <class T>
binaryTreeNode<T> *binaryTree<T>::parent(binaryTreeNode<T> *start, binaryTreeNode<T> *tmp)
{
    if (start == nullptr)
    {
        return nullptr;
    }
    if (start->rchild == tmp || start->lchild == tmp)
    {
        return start;
    }
    binaryTreeNode<T> *p;
    p = parent(start->lchild, tmp);
    if (p != nullptr)
    {
        return p;
    }
    p = parent(start->rchild, tmp);
    if (p != nullptr)
    {
        return p;
    }
    return nullptr;
}
template <class T>
binaryTreeNode<T> *binaryTree<T>::parent(binaryTreeNode<T> *tmp)
{
    return parent(root, tmp);
}
template <class T>
binaryTreeNode<T> *binaryTree<T>::lchi(binaryTreeNode<T> *tmp)
{
    if (tmp == nullptr)
    {
        return nullptr;
    }
    else
    {
        return tmp->lchild;
    }
}
template <class T>
binaryTreeNode<T> *binaryTree<T>::rchi(binaryTreeNode<T> *tmp)
{
    if (tmp == nullptr)
    {
        return nullptr;
    }
    else
    {
        return tmp->rchild;
    }
}
template <class T>
binaryTreeNode<T> *binaryTree<T>::Find(const T &item, binaryTreeNode<T> *tmp) const
{
    if (tmp == nullptr)
    {
        return nullptr;
    }
    if (item == tmp->data)
    {
        return tmp;
    }
    binaryTreeNode<T> *fir = Find(item, tmp->lchild);
    if (fir != nullptr)
    {
        return fir;
    }
    binaryTreeNode<T> *sec = Find(item, tmp->rchild);
    if (sec != nullptr)
    {
        return sec;
    }
    return nullptr;
}
template <class T>
int binaryTree<T>::getHeightByItem(const T &item, binaryTreeNode<T> *tmp, int height)
{
    if (tmp == nullptr)
    {
        return -1;
    }
    if (item == tmp->data)
    {
        return height;
    }
    int fir = getHeightByItem(item, tmp->lchild, height + 1);
    if (fir != -1)
    {
        return fir;
    }
    int sec = getHeightByItem(item, tmp->rchild, height + 1);
    if (sec != -1)
    {
        return sec;
    }
    return -1;
}
template <class T>
int binaryTree<T>::sizes(binaryTreeNode<T> *tmp)
{
    if (tmp == nullptr)
    {
        return 0;
    }
    // std::cout << "hhh" << std::endl;
    int sum = 0;
    bool f1 = tmp->lchild == nullptr ? false : true;
    bool f2 = tmp->rchild == nullptr ? false : true;
    if (!(f1 || f2))
    {
        sum++;
    }
    // int s1 = 0, s2 = 0;
    sum += sizes(tmp->lchild);
    sum += sizes(tmp->rchild);
    return sum;
}
template <class T>
int binaryTree<T>::height(binaryTreeNode<T> *tmp, int maxn)
{
    // std::cout << maxn << std::endl;
    int ms = maxn;
    if (tmp == nullptr)
    {
        return maxn - 1;
    }
    int h1 = height(tmp->lchild, maxn + 1);
    int h2 = height(tmp->rchild, maxn + 1);
    ms = h1 > h2 ? h1 : h2;
    return ms;
}
template <class T>
void binaryTree<T>::preOrder(binaryTreeNode<T> *tmp)
{
    // std::cout << "111" << std::endl;
    if (tmp == nullptr)
    {
        // std::cout << "112" << std::endl;
        return;
    }
    // std::cout << "113" << std::endl;
    output(tmp);
    // std::cout << "114" << std::endl;
    preOrder(tmp->lchild);
    // std::cout << "115" << std::endl;
    preOrder(tmp->rchild);
    // std::cout << "116" << std::endl;
}
template <class T>
void binaryTree<T>::preOrder()
{
    preOrder(root);
}
template <class T>
void binaryTree<T>::inOrder(binaryTreeNode<T> *tmp)
{
    if (tmp == nullptr)
    {
        return;
    }
    inOrder(tmp->lchild);
    output(tmp);
    inOrder(tmp->rchild);
}
template <class T>
void binaryTree<T>::inOrder()
{
    inOrder(root);
}
template <class T>
void binaryTree<T>::postOrder(binaryTreeNode<T> *tmp)
{
    if (tmp == nullptr)
    {
        return;
    }
    postOrder(tmp->lchild);
    postOrder(tmp->rchild);
    output(tmp);
}
template <class T>
void binaryTree<T>::postOrder()
{
    postOrder(root);
}
template <class T>
void binaryTree<T>::preOrder2(binaryTreeNode<T> *tmp)
{
    std::stack<binaryTreeNode<T> *> S;
    binaryTreeNode<T> *p = getRoot();
    S.push(nullptr);
    while (p != nullptr)
    {
        output(p);
        if (p->rchild != nullptr)
        {
            S.push(p->rchild);
        }
        if (p->lchild != nullptr)
        {
            p = p->lchild;
        }
        else
        {
            p = S.top();
            S.pop();
        }
    }
}
template <class T>
void binaryTree<T>::inOrder2(binaryTreeNode<T> *tmp)
{
    std::stack<binaryTreeNode<T> *> S;
    binaryTreeNode<T> *p = getRoot();
    do
    {
        while (p != nullptr)
        {
            S.push(p);
            p = p->lchild;
        }
        if (!S.empty())
        {
            p = S.top();
            S.pop();
            output(p);
            p = p->rchild;
        }
    } while (p != nullptr || !S.empty());
}

template <class T>
void binaryTree<T>::output(binaryTreeNode<T> *tmp)
{
    // std::cout << "222" << std::endl;
    std::cout << tmp->data << " ";
    // std::cout << "223" << std::endl;
}
template <class T>
void binaryTree<T>::CreateTree()
{
    destroy(root);
    this->root = CreateTree(this->root);
}

template <class T>
binaryTreeNode<T> *binaryTree<T>::CreateTree(binaryTreeNode<T> *tree)
{
    T ch;
    std::cin >> ch;

    if (ch == endpos)
    {
        tree = nullptr;
    }
    else
    {
        tree = new binaryTreeNode<T>;
        if (tree == nullptr)
        {
            exit(-1);
        }
        tree->data = ch;
        tree->lchild = CreateTree(tree->lchild);
        tree->rchild = CreateTree(tree->rchild);
    }
    return tree;
}
template <class T>
void binaryTree<T>::Gout(binaryTreeNode<T> *tmp)
{
    if (tmp == nullptr)
    {
        return;
    }
    std::cout << tmp->data;
    bool f1 = tmp->lchild == nullptr ? false : true;
    bool f2 = tmp->rchild == nullptr ? false : true;
    if (f1 || f2)
    {
        std::cout << "(";
    }
    if (f1)
    {
        Gout(tmp->lchild);
    }
    if (f1 && f2)
    {
        std::cout << ",";
    }
    if (f2)
    {
        Gout(tmp->rchild);
    }
    if (f1 || f2)
    {
        std::cout << ")";
    }
}