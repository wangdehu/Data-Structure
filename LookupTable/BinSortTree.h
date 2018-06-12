
template <typename T>
struct BinSortNode
{
    BinSortNode(T t)
        : value(t), lchild(nullptr), rchild(nullptr) {}

    BinSortNode() = default;

    T value;
    BinSortNode<T> *lchild;
    BinSortNode<T> *rchild;
    BinSortNode<T> *parent;
};
template <typename T>
class BinSortTree
{
  public:
    BinSortTree();
    ~BinSortTree();

    void preOrder();
    void inOrder();
    void postOrder();

    BinSortNode<T> *search_recursion(T key);
    BinSortNode<T> *search_Iterator(T key);

    T search_minimun();
    T search_maximum();

    BinSortNode<T> *successor(BinSortNode<T> *x);
    BinSortNode<T> *predecessor(BinSortNode<T> *x);

    void insert(T key);
    void remove(T key);
    void destory();
    BinSortNode<T> *getRoot()
    {
        return this->root;
    }

  private:
    BinSortNode<T> *root;

  private:
    BinSortNode<T> *search(BinSortNode<T> *&p, T key);
    void remove(BinSortNode<T> *p, T key);
    void preOrder(BinSortNode<T> *p);
    void inOrder(BinSortNode<T> *p);
    void postOrder(BinSortNode<T> *p);
    T search_minimun(BinSortNode<T> *p);
    T search_maximum(BinSortNode<T> *p);
    void destory(BinSortNode<T> *&p);
};

template <typename T>
BinSortTree<T>::BinSortTree() : root(nullptr){};

template <typename T>
BinSortTree<T>::~BinSortTree()
{
    destory(root);
};

template <typename T>
void BinSortTree<T>::insert(T key)
{
    BinSortNode<T> *pparent = nullptr;
    BinSortNode<T> *pnode = root;

    while (pnode != nullptr)
    {
        pparent = pnode;
        if (key > pnode->value)
            pnode = pnode->rchild;
        else if (key < pnode->value)
            pnode = pnode->lchild;
        else
            break;
    }

    pnode = new BinSortNode<T>(key);
    if (pparent == nullptr)
    {
        root = pnode;
    }
    else
    {
        if (key > pparent->value)
        {
            pparent->rchild = pnode;
        }
        else
            pparent->lchild = pnode;
    }
    pnode->parent = pparent;
};

template <typename T>
BinSortNode<T> *BinSortTree<T>::search_Iterator(T key)
{
    BinSortNode<T> *pnode = root;
    while (pnode != nullptr)
    {
        if (key == pnode->value)
            return pnode;
        if (key > pnode->value)
            pnode = pnode->rchild;
        else
            pnode = pnode->lchild;
    }
    return nullptr;
};

template <typename T>
BinSortNode<T> *BinSortTree<T>::search_recursion(T key)
{
    return search(root, key);
};

template <typename T>
BinSortNode<T> *BinSortTree<T>::search(BinSortNode<T> *&pnode, T key)
{
    if (pnode == nullptr)
    {
        std::cout << "failed!!!" << std::endl;
        return nullptr;
    }
    if (pnode->value == key)
    {
        std::cout << "-->" << pnode->value << std::endl;
        return pnode;
    }
    std::cout << "-->" << pnode->value << std::endl;
    if (key > pnode->value)
        return search(pnode->rchild, key);
    return search(pnode->lchild, key);
};

template <typename T>
void BinSortTree<T>::remove(T key)
{
    remove(root, key);
};

template <typename T>
void BinSortTree<T>::remove(BinSortNode<T> *pnode, T key)
{
    if (pnode != nullptr)
    {
        if (pnode->value == key)
        {
            BinSortNode<T> *pdel = nullptr;

            if (pnode->lchild == nullptr || pnode->rchild == nullptr)
                pdel = pnode;
            else
                pdel = predecessor(pnode);

            BinSortNode<T> *pchild = nullptr;
            if (pdel->lchild != nullptr)
                pchild = pdel->lchild;
            else
                pchild = pdel->rchild;

            if (pchild != nullptr)
                pchild->parent = pdel->parent;

            if (pdel->parent == nullptr)
                root = pchild;

            else if (pdel->parent->lchild == pdel)
            {
                pdel->parent->lchild = pchild;
            }
            else
            {
                pdel->parent->rchild = pchild;
            }

            if (pnode->value != pdel->value)
                pnode->value = pdel->value;
            delete pdel;
        }
        else if (key > pnode->value)
        {
            remove(pnode->rchild, key);
        }
        else
            remove(pnode->lchild, key);
    }
};

template <typename T>
BinSortNode<T> *BinSortTree<T>::predecessor(BinSortNode<T> *pnode)
{
    if (pnode->lchild != nullptr)
    {
        pnode = pnode->lchild;
        while (pnode->rchild != nullptr)
        {
            pnode = pnode->rchild;
        }
        return pnode;
    }

    BinSortNode<T> *pparent = pnode->parent;
    while (pparent != nullptr && pparent->lchild == pnode)
    {
        pnode = pparent;
        pparent = pparent->parent;
    }
    return pparent;
};
template <typename T>
BinSortNode<T> *BinSortTree<T>::successor(BinSortNode<T> *pnode)
{
    if (pnode->rchild != nullptr)
    {
        pnode = pnode->rchild;
        while (pnode->lchild != nullptr)
        {
            pnode = pnode->lchild;
        }
        return pnode;
    }

    BinSortNode<T> *pparent = pnode->parent;
    while (pparent != nullptr && pparent->rchild == pnode)
    {
        pnode = pparent;
        pparent = pparent->parent;
    }
    return pparent;
};

template <typename T>
void BinSortTree<T>::preOrder()
{
    preOrder(root);
};
template <typename T>
void BinSortTree<T>::preOrder(BinSortNode<T> *p)
{
    if (p != nullptr)
    {
        std::cout << p->value << std::endl;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
};
template <typename T>
void BinSortTree<T>::inOrder()
{
    inOrder(root);
};
template <typename T>
void BinSortTree<T>::inOrder(BinSortNode<T> *p)
{
    if (p != nullptr)
    {
        inOrder(p->lchild);
        std::cout << p->value << std::endl;
        inOrder(p->rchild);
    }
};
template <typename T>
void BinSortTree<T>::postOrder()
{
    postOrder(root);
};
template <typename T>
void BinSortTree<T>::postOrder(BinSortNode<T> *p)
{
    if (p != nullptr)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        std::cout << p->value << std::endl;
    }
};
template <typename T>
T BinSortTree<T>::search_minimun()
{
    return search_minimun(root);
};
template <typename T>
T BinSortTree<T>::search_minimun(BinSortNode<T> *p)
{
    if (p->lchild != nullptr)
        return search_minimun(p->lchild);
    return p->value;
};

template <typename T>
T BinSortTree<T>::search_maximum()
{
    return search_maximum(root);
};
template <typename T>
T BinSortTree<T>::search_maximum(BinSortNode<T> *p)
{
    if (p->rchild != nullptr)
        return search_maximum(p->rchild);
    return p->value;
};

template <typename T>
void BinSortTree<T>::destory()
{
    destory(root);
};
template <typename T>
void BinSortTree<T>::destory(BinSortNode<T> *&p)
{
    if (p != nullptr)
    {
        if (p->lchild != nullptr)
            destory(p->lchild);
        if (p->rchild != nullptr)
            destory(p->rchild);
        delete p;
        p = nullptr;
    }
};