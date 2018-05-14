#include <iostream>
#include <cstdlib>
const int defaultSize = 100;
template <class T>
class SeqList
{
protected:
  T *data;
  int maxSize;
  int last;
  void reSize(int newSize);

public:
  SeqList(int sz = defaultSize);
  SeqList(SeqList<T> &L);
  ~SeqList();
  int Size() const;
  int Length() const;
  int Search(T &x) const;
  Locate(int i) const;
  bool getData(int i, T &x) const;
  void setData(int i, T &x);
  bool Insert(int i, T x);
  bool Remove(int i, T &x);
  bool IsEmpty() const;
  bool IsFull() const;
  void Sort(){};
  void Input_Front();
  void Input_End();
  void Output();
  SeqList<T> operator=(SeqList<T> &L);
};

template <class T>
SeqList<T>::SeqList(int sz)
{
  if (sz > 0)
  {
    maxSize = sz;
    last = -1;
    data = new T[maxSize];
    if (data == nullptr)
    {
      std::cerr << "Storage allocation error" << std::endl;
      exit(1);
    }
  }
}
template <class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
  maxSize = L.Size();
  last = L.Length() - 1;
  T vaule;
  data = new T[maxSize];
  if (data == nullptr)
  {
    std::cerr << "Storage allocation error" << std::endl;
    exit(1);
  }
  for (int i = 1; i <= last + 1; ++i)
  {
    L.getData(i, vaule);
    data[i - 1] = vaule;
  }
}
template <class T>
SeqList<T>::~SeqList()
{
  delete[] data;
}
template <class T>
int SeqList<T>::Size() const
{
  return maxSize;
}
template <class T>
int SeqList<T>::Length() const
{
  return last + 1;
}
template <class T>
int SeqList<T>::Search(T &x) const
{

  for (int i = 0; i <= last; ++i)
  {
    if (data[i] == x)
      return i + 1;
  }
  return 0;
}
template <class T>
int SeqList<T>::Locate(int i) const
{

  if (i >= 1 && i <= last + 1)
    return i;
  else
    return 0;
}
template <class T>
bool SeqList<T>::getData(int i, T &x) const
{
  if (i > 0 && i <= last + 1)
  {
    x = data[i - 1];
    return true;
  }
  else
  {
    return false;
  }
}
template <class T>
void SeqList<T>::setData(int i, T &x)
{
  if (i > 0 && i <= last + 1)
    data[i - 1] = x;
}
template <class T>
bool SeqList<T>::Insert(int i, T x)
{
  if (last == maxSize - 1)
  {
    return false;
  }
  if (i < 0 || i > last + 1)
  {
    return false;
  }
  for (int j = last; j >= i; --j)
  {
    data[j + 1] = data[j];
  }
  data[i] = x;
  last++;
  if (!last)
  {
    last++;
  }
  return true;
}
template <class T>
bool SeqList<T>::Remove(int i, T &x)
{
  if (last == -1)
  {
    return false;
  }
  if (i < 0 || i > last + 1)
  {
    return false;
  }
  x = data[i - 1];
  for (int j = i; j <= last; ++j)
  {
    data[j - 1] = data[j];
  }
  last--;
  return true;
}
template <class T>
bool SeqList<T>::IsEmpty() const
{
  return last == -1;
}
template <class T>
bool SeqList<T>::IsFull() const
{
  return last == maxSize - 1;
}
template <class T>
void SeqList<T>::reSize(int newSize)
{
  if (newSize < 0)
  {
    std::cerr << "Invalid array size" << std::endl;
    return;
  }
  if (newSize != maxSize)
  {
    T *newarray = new T[newSize];
    if (newarray == nullptr)
    {
      std::cerr << "Storage allocation error" << std::endl;
      exit(1);
    }
    int n = last + 1;
    T *src = data;
    T *des = newarray;
    while (n--)
    {
      *des++ = *src++;
    }
    delete[] data;
    data = newarray;
    maxSize = newSize;
  }
}
template <class T>
void SeqList<T>::Input_End()
{
  std::cout << "Input the number of SeqlList:";
  while (1)
  {
    std::cin >> last;
    if (last <= maxSize - 1)
      break;
    std::cout << "the number is error!" << std::endl;
  }
  for (int i = 0; i < last; ++i)
  {
    std::cin >> data[i];
    //std::cout << i + 1 << std::endl;
  }
}
template <class T>
void SeqList<T>::Input_Front()
{
  std::cout << "Input the number of SeqlList:";
  while (1)
  {
    std::cin >> last;
    if (last <= maxSize - 1)
      break;
    std::cout << "the number is error!" << std::endl;
  }
  for (int i = last - 1; i >= 0; --i)
  {
    std::cin >> data[i];
    //std::cout << i + 1 << std::endl;
  }
}
template <class T>
void SeqList<T>::Output()
{
  std::cout << "the last element's pos is " << last << std::endl;
  for (int i = 0; i < last; ++i)
  {
    std::cout << "#" << i + 1 << ":" << data[i] << std::endl;
  }
}
template <class T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L)
{
  maxSize = L.Size();
  last = L.Length() - 1;
  T vaule;
  data = new T[maxSize];
  if (data == nullptr)
  {
    std::cerr << "Storage allocation error" << std::endl;
    exit(1);
  }
  for (int i = 1; i <= last + 1; ++i)
  {
    L.getData(i, vaule);
    data[i - 1] = vaule;
  }
}
