#ifndef _C_Stack_H
#define _C_Stack_H

#include "CNode.h"
#include <iostream>
using namespace std;

template<class T>
class C_Stack
{
private:
    CNode<T>* m_pStackNodePointer;
    unsigned int m_uiSize;
    unsigned int m_uiNumOfElements;
public:
    C_Stack(unsigned int uiSize);
    ~C_Stack();
    void push(T data);
    void pop();
    T top();
    bool isEmpty();
};
#endif