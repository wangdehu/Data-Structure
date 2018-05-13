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
  List(List<T> &L);
  ~List();
  void makeEmpty();
  int Length() const;
  LinkNode<T> *getHead() const;
  int Search(T &x) const;
  LinkNode<T> *Locate(int i) const;
  bool getData(int i, T &x) const;
  void setData(int i, T &x);
  bool Insert(int i, T x);
  bool Remove(int i, T &x);
  bool IsEmpty() const;
  bool IsFull() const;
  void Sort(){};
  void Input_Front(const T &x);
  void Input_End(const T &x);
  void Output();
  List<T> operator=(List<T> &L);
};

template <class T>
List<T>::List()
{
  first = new LinkNode<T>;
}
template <class T>
List<T>::List(List<T> &L)
{
  T value;
  LinkNode<T> *src = L.getHead();
  LinkNode<T> *des = first = new LinkNode<T>;
  while (src->link != nullptr)
  {
    value = src->link->data;
    des->link = new LinkNode<T>(value);
    des = des->link;
    src = src->link;
  }
  des->link = nullptr;
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
int List<T>::Length() const
{
  LinkNode<T> *p = first->link;
  int count = 0;
  while (p != nullptr)
  {
    p = p->link;
    count++;
  }
  return count;
}
template <class T>
LinkNode<T> *List<T>::getHead() const
{
  return first;
}
template <class T>
int List<T>::Search(T &x) const
{
  int i = 1;
  bool flag = true;
  LinkNode<T> *current = first->link;
  while (current != nullptr)
  {
    if (current->data == x)
    {
      flag = false;
      break;
    }
    else
    {
      current = current->link;
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
LinkNode<T> *List<T>::Locate(int i) const
{
  if (i <= 0)
  {
    return nullptr;
  }
  LinkNode<T> *current = first;
  int k = 0;
  while (current != nullptr && k < i)
  {
    current = current->link;
    k++;
  }
  return current;
}
template <class T>
bool List<T>::getData(int i, T &x) const
{
  if (i <= 0)
    return false;
  LinkNode<T> *current = Locate(i);
  if (current == nullptr)
    return false;
  else
  {
    x = current->data;
    return true;
  }
}
template <class T>
void List<T>::setData(int i, T &x)
{
  if (i <= 0)
    return;
  ;
  LinkNode<T> *current = Locate(i);
  if (current == nullptr)
    return;
  else
  {
    current->data = x;
  }
}
template <class T>
bool List<T>::Insert(int i, T x)
{

  LinkNode<T> *current = Locate(i);
  if (i != 0 && current == nullptr)
  {
    return false;
  }
  if (i == 0)
    current = first;
  LinkNode<T> *newNode = new LinkNode<T>(x);
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
bool List<T>::Remove(int i, T &x)
{
  LinkNode<T> *current = Locate(i - 1);

  if (current == nullptr || current->link == nullptr)
  {
    return false;
  }

  LinkNode<T> *del = current->link;
  current->link = del->link;
  x = del->data;
  delete del;
  return true;
}
template <class T>
bool List<T>::IsEmpty() const
{
  return first->link == nullptr;
}
template <class T>
bool List<T>::IsFull() const
{
  return false;
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
void List<T>::Input_Front(const T &endTag)
{
  LinkNode<T> *newNode;
  T value;
  makeEmpty();
  std::cin >> value;
  while (value != endTag)
  {
    newNode = new LinkNode<T>(value);
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
template <class T>
List<T> List<T>::operator=(List<T> &L)
{
  T value;
  LinkNode<T> *src = L.getHead();
  LinkNode<T> *des = first = new LinkNode<T>;
  while (src->link != nullptr)
  {
    value = src->link->data;
    des->link = new LinkNode<T>(value);
    des = des->link;
    src = src->link;
  }
  des->link = nullptr;
  return *this;
}
