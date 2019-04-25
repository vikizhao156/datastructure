#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 100
#define M 10010
template<class T>
class Queue //队列类的基本定义
{
public:
    bool IsFull() const;
    bool IsEmpty() const;
    T front();
    void Pop();
    void Push(T &e);
    Queue(int size);
    ~Queue();
private:
    T *base;
    int top,rear;
    int maxsize;
};
template<class T>
bool Queue<T>::IsFull() const
{
    return rear == maxsize;
}
template<class T>
bool Queue<T>::IsEmpty() const
{
    return rear == top;
}
template<class T>
Queue<T>::Queue(int size):maxsize(size)
{
    base = new T[maxsize];
    if (base == NULL)
    {
        cout<<"Memory Allocation Failed!"<<endl;exit(0);
    }
    top = rear = 0;
}
template<class T>
void Queue<T>::Pop()
{
    top++;
}
template<class T>
void Queue<T>::Push(T &e)
{
    base[rear++] = e;
}
template<class T>
T Queue<T>::front()
{
    return base[top];
}
template<class T>
Queue<T>::~Queue()
{
    delete [] base;
}
#endif // HEAD_H
