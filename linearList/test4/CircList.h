#include <cstdlib>
template <class T>
struct CircLinkNode
{
    T data;
    CircLinkNode<T> *link;
    CircLinkNode(CircLinkNode<T> *ptr = nullptr)
    {
        link = ptr;
    }
    CircLinkNode(const T &item, CircLinkNode<T> *ptr = nullptr)
    {
        data = item;
        link = ptr;
    }
};
template <class T>
class CircList
{
  protected:
    CircLinkNode<T> *first;

  public:
    CircList();
    CircList(const T &x);
    CircList(CircList<T> &L);
    ~CircList();
    void makeEmpty();
    int Length() const;
    CircLinkNode<T> *getHead() const;
    bool setHead(int &i) const;
    CircLinkNode<T> *Search(T &x) const;
    CircLinkNode<T> *Locate(int i) const;
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
    CircList<T> operator=(CircList<T> &L);
};

template <class T>
CircList<T>::CircList()
{
    first = new CircLinkNode<T>;
    first->link = first;
}
template <class T>
CircList<T>::CircList(const T &x)
{
    first = new CircLinkNode<T>(x);
    first->link = first;
}
template <class T>
CircList<T>::CircList(CircList<T> &L)
{
    T value;
    CircLinkNode<T> *src = L.getHead();
    CircLinkNode<T> *des = first = new CircLinkNode<T>;
    while (src->link != L.first)
    {
        value = src->link->data;
        des->link = new CircLinkNode<T>(value);
        des = des->link;
        src = src->link;
    }
    des->link = first;
}
template <class T>
CircList<T>::~CircList()
{
    makeEmpty();
}
template <class T>
void CircList<T>::makeEmpty()
{
    CircLinkNode<T> *q;
    while (first->link != first)
    {
        q = first->link;
        first->link = q->link;
        delete q;
    }
    delete first;
}
template <class T>
int CircList<T>::Length() const
{
    CircLinkNode<T> *p = first;
    int count = 0;
    while (p->link != first)
    {
        p = p->link;
        count++;
    }
    return count;
}
template <class T>
CircLinkNode<T> *CircList<T>::getHead() const
{
    return first;
}
template <class T>
CircLinkNode<T> *CircList<T>::Search(T &x) const
{

    CircLinkNode<T> *current = first->link;
    while (current != first)
    {
        if (current->data == x)
            return current;
        else
            current = current->link;
    }
    return nullptr;
}
template <class T>
CircLinkNode<T> *CircList<T>::Locate(int i) const
{
    if (i <= 0 || i > Length())
        return nullptr;
    CircLinkNode<T> *current = first->link;
    int k = 1;
    while (current != first && k < i)
    {
        current = current->link;
        k++;
    }
    return current;
}
template <class T>
bool CircList<T>::getData(int i, T &x) const
{
    if (i <= 0)
        return false;
    CircLinkNode<T> *current = Locate(i);
    if (current == nullptr)
        return false;
    else
    {
        x = current->data;
        return true;
    }
}
template <class T>
void CircList<T>::setData(int i, T &x)
{
    if (i <= 0)
        return;
    CircLinkNode<T> *current = Locate(i);
    if (current == nullptr)
        return;
    else
    {
        current->data = x;
    }
}
template <class T>
bool CircList<T>::Insert(int i, T &x)
{
    CircLinkNode<T> *current = Locate(i);

    if (current == nullptr)
        return false;
    CircLinkNode<T> *newNode = new CircLinkNode<T>(x);
    if (newNode == nullptr)
    {
        std::cout << "Storage allocation error" << std::endl;
        exit(1);
    }
    newNode->link = current->link;
    current->link = newNode;
    return true;
}
template <class T>
bool CircList<T>::Remove(int i, T &x)
{
    CircLinkNode<T> *current = Locate(i - 1);

    if (current == nullptr || current->link == first)
    {
        return false;
    }

    CircLinkNode<T> *del = current->link;
    current->link = del->link;
    x = del->data;
    delete del;
    return true;
}
template <class T>
bool CircList<T>::IsEmpty() const
{
    return first->link == first;
}
template <class T>
bool CircList<T>::IsFull() const
{
    return false;
}
template <class T>
void CircList<T>::Input_End(const T &endTag)
{
    CircLinkNode<T> *newNode, *last;
    T value;
    makeEmpty();
    last = first;
    std::cin >> value;
    while (value != endTag)
    {
        newNode = new CircLinkNode<T>(value);
        if (newNode == nullptr)
        {
            std::cout << "Storage allocation error" << std::endl;
            exit(1);
        }
        last->link = newNode;
        last = newNode;
        std::cin >> value;
    }
    last->link = first;
}
template <class T>
void CircList<T>::Input_Front(const T &endTag)
{
    CircLinkNode<T> *newNode;
    T value;
    makeEmpty();
    std::cin >> value;
    while (value != endTag)
    {
        newNode = new CircLinkNode<T>(value);
        if (newNode == nullptr)
        {
            std::cout << "Storage allocation error" << std::endl;
            exit(1);
        }
        newNode->link = first->link;
        first->link = newNode;
        std::cin >> value;
    }
}
template <class T>
void CircList<T>::Output()
{
    CircLinkNode<T> *current = first->link;
    int cou = 1;
    while (current != first)
    {
        std::cout << "#" << cou++ << ":" << current->data << std::endl;
        current = current->link;
    }
}
template <class T>
CircList<T> CircList<T>::operator=(CircList<T> &L)
{
    T value;
    CircLinkNode<T> *src = L.getHead();
    CircLinkNode<T> *des = first = new CircLinkNode<T>;
    while (src->link != L.first)
    {
        value = src->link->data;
        des->link = new CircLinkNode<T>(value);
        des = des->link;
        src = src->link;
    }
    des->link = first;
    return *this;
}
