#include "SeqStack.h"
#include <cstdlib>
template <class T>
struct LinkNode
{
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr = nullptr)
    {
        link = ptr;
    }
    LinkNode(const T &item, LinkNode<T> *ptr = nullptr)
    {
        data = item;
        link = ptr;
    }
};
template <class T>
class List
{
  protected:
    LinkNode<T> *first;

  public:
    List();
    ~List();
    void reverse();
    void makeEmpty();
    void Input_End(const T &endTag);
    void Output();
};
template <class T>
void List<T>::reverse()
{
    SeqStack<LinkNode<T> *> S;
    LinkNode<T> *current = first->link;
    if (current == nullptr)
    {
        return;
    }
    while (current != nullptr)
    {
        S.Push(current);
        current = current->link;
    }
    LinkNode<T> *pre = first;
    while (!S.IsEmpty())
    {
        S.Pop(pre->link);
        pre = pre->link;
    }
    pre->link = nullptr;
}
template <class T>
List<T>::List()
{
    first = new LinkNode<T>;
}
template <class T>
List<T>::~List()
{
    makeEmpty();
}
template <class T>
void List<T>::makeEmpty()
{
    LinkNode<T> *q;
    while (first->link != nullptr)
    {
        q = first->link;
        first->link = q->link;
        delete q;
    }
}
template <class T>
void List<T>::Input_End(const T &endTag)
{
    LinkNode<T> *newNode, *last;
    T value;
    makeEmpty();
    last = first;
    std::cin >> value;
    while (value != endTag)
    {
        newNode = new LinkNode<T>(value);
        if (newNode == nullptr)
        {
            std::cout << "Storage allocation error" << std::endl;
            exit(1);
        }
        last->link = newNode;
        last = newNode;
        std::cin >> value;
    }
    last->link = nullptr;
}
template <class T>
void List<T>::Output()
{
    LinkNode<T> *current = first->link;
    int cou = 1;
    while (current != nullptr)
    {
        std::cout << "#" << cou++ << ":" << current->data << std::endl;
        current = current->link;
    }
}