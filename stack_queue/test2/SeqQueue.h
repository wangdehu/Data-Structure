#ifndef _SeqQueue_
#define _SeqQueue_
#include <iostream>
#include <cstdlib>
const int defaultSize = 100;
template <class T>
class SeqQueue
{
  protected:
    T *data;
    int maxSize;
    int front, rear;

  public:
    SeqQueue(int sz = defaultSize);
    ~SeqQueue();
    void Push(const T &tmp);
    bool Pop(T &tmp);
    bool getFront(T &tmp);
    bool IsEmpty() const;
    bool IsFull() const;
    int getSize() const;
    void clear();
    void InSize();
    void Desize();
    // friend std::ostream &operator<<(std::ostream &out, SeqQueue<T> &s);
};
template <class T>
SeqQueue<T>::SeqQueue(int sz) : front(0), rear(0), maxSize(sz)
{
    T *newArray = new T[sz];
    if (newArray == nullptr)
    {
        std::cerr << "Storage allocation error" << std::endl;
        exit(1);
    }
    data = newArray;
}
template <class T>
SeqQueue<T>::~SeqQueue()
{
    delete[] data;
}
template <class T>
void SeqQueue<T>::Push(const T &tmp)
{
    if (IsFull())
    {
        InSize();
    }
    data[rear++] = tmp;
    rear %= maxSize;
}
template <class T>
bool SeqQueue<T>::Pop(T &tmp)
{
    if (IsEmpty())
        return false;
    tmp = data[front++];
    front %= maxSize;
    if (getSize() < maxSize / 4)
    {
        Desize();
    }
    return true;
}
template <class T>
bool SeqQueue<T>::getFront(T &tmp)
{
    if (IsEmpty())
    {
        return false;
    }
    else
    {
        tmp = data[front];
        return true;
    }
}
template <class T>
bool SeqQueue<T>::IsEmpty() const
{
    return front == rear;
}
template <class T>
bool SeqQueue<T>::IsFull() const
{
    return (rear + 1) == front;
}
template <class T>
int SeqQueue<T>::getSize() const
{
    return (rear - front + maxSize) % maxSize;
}
template <class T>
void SeqQueue<T>::clear()
{
    front = rear = 0;
}
template <class T>
void SeqQueue<T>::InSize()
{
    maxSize *= 2;
    T *newArray = new T[maxSize];
    if (newArray == nullptr)
    {
        std::cerr << "Storage allocation error" << std::endl;
        exit(1);
    }
    int cnt = 0;
    for (int i = front; i != rear; i = (i + 1) % maxSize)
    {
        newArray[cnt++] = data[i];
    }
    delete[] data;
    front = 0;
    rear = cnt;
    data = newArray;
}
template <class T>
void SeqQueue<T>::Desize()
{
    maxSize /= 2;
    T *newArray = new T[maxSize];
    if (newArray == nullptr)
    {
        std::cerr << "Storage allocation error" << std::endl;
        exit(1);
    }
    int cnt = 0;
    for (int i = front; i != rear; i = (i + 1) % maxSize)
    {
        newArray[cnt++] = data[i];
    }
    delete[] data;
    front = 0;
    rear = cnt;
    data = newArray;
}
// template <class T>
// std::ostream &operator<<(std::ostream &out, SeqQueue<T> &q)
// {

//     out << "front  = " << q.front <<"rear  =  <<q.rear<< std::endl;
//     for (int i = q.front; i != q.rear; i=(i+1)%maxSize)
//     {
//         out <<i<<"  "<< q.data[i] << std::endl;
//     }
//     return out;
// }
#endif