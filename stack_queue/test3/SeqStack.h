#ifndef _SEQSTACK_
#define _SEQSTACK_
#include <iostream>
#include <cstdlib>
const int defaultSize = 100;
const int increaseSize = 100;
template <class T>
class SeqStack
{
  protected:
    T *data;
    int maxSize;
    int top;
    void overflowProcess();

  public:
    SeqStack(int sz = defaultSize);
    ~SeqStack();
    void Push(const T &tmp);
    bool Pop(T &tmp);
    bool getTop(T &tmp);
    bool IsEmpty() const;
    bool IsFull() const;
    int getSize() const;
    void clear();
    // friend std::ostream &operator<<(std::ostream &out, SeqStack<T> &s);
};
template <class T>
SeqStack<T>::SeqStack(int sz)
{
    T *newArray = new T[sz];
    if (newArray == nullptr)
    {
        std::cerr << "Storage allocation error" << std::endl;
        exit(1);
    }
    data = newArray;
    top = -1;
    maxSize = sz;
}
template <class T>
SeqStack<T>::~SeqStack()
{
    delete[] data;
}
template <class T>
void SeqStack<T>::Push(const T &tmp)
{
    if (IsFull())
        overflowProcess();
    data[++top] = tmp;
}
template <class T>
bool SeqStack<T>::Pop(T &tmp)
{
    if (IsEmpty())
        return false;
    tmp = data[top--];
    return true;
}
template <class T>
bool SeqStack<T>::getTop(T &tmp)
{
    if (IsEmpty())
    {
        return false;
    }
    else
    {
        tmp = data[top];
        return true;
    }
}
template <class T>
bool SeqStack<T>::IsEmpty() const
{
    return top == -1;
}
template <class T>
bool SeqStack<T>::IsFull() const
{
    return top == maxSize - 1;
}
template <class T>
int SeqStack<T>::getSize() const
{
    return top + 1;
}
template <class T>
void SeqStack<T>::clear()
{
    top = -1;
}
template <class T>
void SeqStack<T>::overflowProcess()
{
    maxSize += increaseSize;
    T *newArray = new T[maxSize];
    if (newArray == nullptr)
    {
        std::cerr << "Storage allocation error" << std::endl;
        exit(1);
    }
    for (int i = 0; i <= top; ++i)
    {
        newArray[i] = data[i];
    }
    delete[] data;
    data = newArray;
    ;
}
// template <class T>
// std::ostream &operator<<(std::ostream &out, SeqStack<T> &s)
// {

//     out << "top  = " << s.top << std::endl;
//     for (int i = 0; i <= s.top; ++i)
//     {
//         out << s.data[i] << std::endl;
//     }
//     return out;
// }
#endif