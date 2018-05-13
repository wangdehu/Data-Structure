#include <cstdlib>
template <class T>
struct DblNode
{
    T data;
    DblNode<T> *lLink, *rLink;
    DblNode(DblNode<T> *left = nullptr, DblNode<T> *right = nullptr) : lLink(left), rLink(right) {}
    DblNode(const T &value, DblNode<T> *left = nullptr, DblNode<T> *right = nullptr) : data(value), lLink(left), rLink(right) {}
};
template <class T>
class DblList
{
  protected:
    DblNode<T> *first;

  public:
    DblList();
    DblList(DblList<T> &L);
    ~DblList();
    void makeEmpty();
    int Length() const;
    DblNode<T> *getHead() const;
    int Search(T &x) const;
    DblNode<T> *Locate(int i) const;
    bool getData(int i, T &x) const;
    void setData(int i, T &x);
    bool Insert(int i, T &x);
    bool Remove(int i, T &x);
    bool IsEmpty() const;
    bool IsFull() const;
    void Sort(){};
    void Input_Front(const T &x);
    void Input_End(const T &x);
    void Output();
    DblList<T> operator=(DblList<T> &L);
};

template <class T>
DblList<T>::DblList()
{
    first = new DblNode<T>;
}
template <class T>
DblList<T>::DblList(DblList<T> &L)
{
    T value;
    DblNode<T> *src = L.getHead();
    DblNode<T> *des = first = new DblNode<T>;
    while (src->rLink != nullptr)
    {
        value = src->rLink->data;
        des->rLink = new DblNode<T>(value);
        des->rLink->lLink = des;
        des = des->rLink;
        src = src->rLink;
    }
    des->rLink = nullptr;
}
template <class T>
DblList<T>::~DblList()
{
    makeEmpty();
}
template <class T>
void DblList<T>::makeEmpty()
{
    DblNode<T> *q;
    while (first->rLink != nullptr)
    {
        q = first->rLink;
        first->rLink = q->rLink;
        delete q;
    }
}
template <class T>
int DblList<T>::Length() const
{
    DblNode<T> *p = first->rLink;
    int count = 0;
    while (p != nullptr)
    {
        p = p->rLink;
        count++;
    }
    return count;
}
template <class T>
DblNode<T> *DblList<T>::getHead() const
{
    return first;
}
template <class T>
int DblList<T>::Search(T &x) const
{
    int i = 1;
    bool flag = true;
    DblNode<T> *current = first->rLink;
    while (current != nullptr)
    {
        if (current->data == x)
        {
            flag = false;
            break;
        }
        else
        {
            current = current->rLink;
            i++;
        }
    }
    if (flag)
    {
        return -1;
    }
    return i;
}
template <class T>
DblNode<T> *DblList<T>::Locate(int i) const
{
    if (i <= 0)
        return nullptr;
    DblNode<T> *current = first;
    int k = 0;
    while (current != nullptr && k < i)
    {
        current = current->rLink;
        k++;
    }
    return current;
}
template <class T>
bool DblList<T>::getData(int i, T &x) const
{
    if (i <= 0)
        return false;
    DblNode<T> *current = Locate(i);
    if (current == nullptr)
        return false;
    else
    {
        x = current->data;
        return true;
    }
}
template <class T>
void DblList<T>::setData(int i, T &x)
{
    if (i <= 0)
        return;
    ;
    DblNode<T> *current = Locate(i);
    if (current == nullptr)
        return;
    else
    {
        current->data = x;
    }
}
template <class T>
bool DblList<T>::Insert(int i, T &x)
{
    DblNode<T> *current = Locate(i);

    if (current == nullptr)
        return false;
    DblNode<T> *newNode = new DblNode<T>(x);
    if (newNode == nullptr)
    {
        std::cout << "Storage allocation error" << std::endl;
        exit(1);
    }
    newNode->rLink = current->rLink;
    current->rLink->lLink = newNode;
    newNode->lLink = current;
    current->rLink = newNode;
    return true;
}
template <class T>
bool DblList<T>::Remove(int i, T &x)
{
    DblNode<T> *current = Locate(i - 1);

    if (current == nullptr || current->rLink == nullptr)
    {
        return false;
    }

    DblNode<T> *del = current->rLink;
    del->rLink->lLink = current;
    current->rLink = del->rLink;
    x = del->data;
    delete del;
    return true;
}
template <class T>
bool DblList<T>::IsEmpty() const
{
    return first->rLink == nullptr;
}
template <class T>
bool DblList<T>::IsFull() const
{
    return false;
}
template <class T>
void DblList<T>::Input_End(const T &endTag)
{
    DblNode<T> *newNode, *last;
    T value;
    makeEmpty();
    last = first;
    std::cin >> value;
    while (value != endTag)
    {
        newNode = new DblNode<T>(value);
        if (newNode == nullptr)
        {
            std::cout << "Storage allocation error" << std::endl;
            exit(1);
        }
        last->rLink = newNode;
        newNode->lLink = last;
        last = newNode;
        std::cin >> value;
    }
    last->rLink = nullptr;
}
template <class T>
void DblList<T>::Input_Front(const T &endTag)
{
    DblNode<T> *newNode;
    T value;
    makeEmpty();
    std::cin >> value;
    while (value != endTag)
    {
        newNode = new DblNode<T>(value);
        if (newNode == nullptr)
        {
            std::cout << "Storage allocation error" << std::endl;
            exit(1);
        }
        newNode->rLink = first->rLink;
        first->rLink->lLink = newNode;
        first->rLink = newNode;
        newNode->lLink = first;
        std::cin >> value;
    }
}
template <class T>
void DblList<T>::Output()
{
    DblNode<T> *current = first->rLink;
    int cou = 1;
    while (current != nullptr)
    {
        std::cout << "#" << cou++ << ":" << current->data << std::endl;
        current = current->rLink;
    }
}
template <class T>
DblList<T> DblList<T>::operator=(DblList<T> &L)
{
    T value;
    DblNode<T> *src = L.getHead();
    DblNode<T> *des = first = new DblNode<T>;
    while (src->rLink != nullptr)
    {
        value = src->rLink->data;
        des->rLink = new DblNode<T>(value);
        des->rLink->lLink = des;
        des = des->rLink;
        src = src->rLink;
    }
    des->rLink = nullptr;
    return *this;
}
