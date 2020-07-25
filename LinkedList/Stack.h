#ifndef _Stack_H
#define _Stack_H

#include "../LinkedList/LinkedList.h"
using namespace std;

template<class T>
class Stack
{
private:
    unsigned int m_uiStackPointer;
    C_LinkedList<T> m_StackBuffer;
public:
    Stack();
    ~Stack();
    void push(T data);
    void pop();
    T top();
    bool isEmpty();
};
#endif
