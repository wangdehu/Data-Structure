#include <iostream>
#include <algorithm>
#include <stack>
template <class T>
struct ThreadTreeNode
{
    T data;
    int ltag,rtag;
    ThreadTreeNode<T> *lchild, *rchild;

    ThreadTreeNode(T tmp) : data(tmp), lchild(nullptr), rchild(nullptr),ltag(0),rtag(0) {}
    ThreadTreeNode() : lchild(nullptr), rchild(nullptr),ltag(0),rtag(0) {}
};
template <class T>
class ThreadTree
{
  private:
    ThreadTreeNode<T> *root;
    T endpos;

    void destroy(ThreadTreeNode<T> *tmp);

  public:
    ThreadTree() : root(nullptr) {}
    ThreadTree(T tmp) : root(nullptr), endpos(tmp) {}
    ThreadTree(ThreadTreeNode<T> *tmp) : root(tmp), endpos('.') {}
    ~ThreadTree();
    void createinThread(ThreadTreeNode<T> *now,ThreadTreeNode <T>*&pre );
    void createinThread();


ThreadTreeNode<T> *first(ThreadTreeNode<T> *tmp);
// ThreadTreeNode<T> *last(ThreadTreeNode<T> *tmp);
ThreadTreeNode<T> *next(ThreadTreeNode<T> *tmp);
// ThreadTreeNode<T> *prior(ThreadTreeNode<T> *tmp);

    void inorderByThread();
    void CreateTree();
    ThreadTreeNode<T> *CreateTree(ThreadTreeNode<T> *tree);
};
template <class T>
ThreadTree<T>::~ThreadTree()
{
    destroy(root);
}
template<class T>
void ThreadTree<T>::inorderByThread() {
    ThreadTreeNode<T> *now;
    for (now = first(now); now != nullptr; now = next(now)) {
        std::cout << now->data << " ";
    }
}
template <class T>
void ThreadTree<T>::createinThread(ThreadTreeNode<T> *now,ThreadTreeNode <T>*&pre ) {
        if (now == nullptr) return;
        createinThread(now->lchild,pre);
        if (now->lchild == nullptr) {
            now->lchild = pre;
            now->ltag = 1;
        }
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = now;
            pre->rtag = 1;
        }
        pre = now;
        createinThread(now->rchild,pre);
    }
template <class T>
void ThreadTree<T>::createinThread() {
    ThreadTreeNode <T>*pre = nullptr;
    if (root != nullptr) {
        createinThread(root,pre);
        pre->rchild = nullptr;
        pre->rtag = 1;
    }
}
template <class T>
void ThreadTree<T>::destroy(ThreadTreeNode<T> *tmp)
{
    if (tmp != nullptr)
    {
        destroy(tmp->lchild);
        destroy(tmp->rchild);
        delete tmp;
    }
}
template <class T>
ThreadTreeNode<T> *ThreadTree<T>::first(ThreadTreeNode<T> *tmp) {
    ThreadTreeNode<T> *p = tmp;
    while (p->ltag == 0) p = p->lchild;
    return p;
}
template <class T>
ThreadTreeNode<T> *ThreadTree<T>::next(ThreadTreeNode<T> *tmp) {
    ThreadTreeNode<T> *p = tmp->rchild;
    if (tmp->rtag == 0)
        return first(p);
    else
        return p;
}
template <class T>
void ThreadTree<T>::CreateTree()
{
    destroy(root);
    this->root = CreateTree(this->root);
}

template <class T>
ThreadTreeNode<T> *ThreadTree<T>::CreateTree(ThreadTreeNode<T> *tree)
{
    T ch;
    std::cin >> ch;

    if (ch == endpos)
    {
        tree = nullptr;
    }
    else
    {
        tree = new ThreadTreeNode<T>;
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