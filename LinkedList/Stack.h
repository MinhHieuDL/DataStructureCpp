#ifndef _C_Stack_H
#define _C_Stack_H

#include "LinkedList.h"
using namespace std;

template<class T>
class C_Stack
{
private:
    unsigned int m_uiC_StackPointer;
    C_LinkedList<T> m_C_StackBuffer;
    unsigned int m_uiSize;
public:
    C_Stack(unsigned int uiSize);
    ~C_Stack();
    void push(T data);
    void pop();
    T top();
    bool isEmpty();
};
#endif
