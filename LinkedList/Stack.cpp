/*
* Date : 25/07/2020
* Author: Minh Hieu
* Name of project: My C_Stack DS
*/

#include "Stack.h"

template<class T>
C_Stack<T>::C_Stack(unsigned int uiSize)
{
    m_uiC_StackPointer = 0;
    m_uiSize = uiSize;
}

template<class T>
C_Stack<T>::~C_Stack()
{
    while(!this->isEmpty())
    {
        this->pop();
    }
}

template<class T>
void C_Stack<T>::push(T data)
{
    if(m_uiC_StackPointer < m_uiSize)
    {
        m_C_StackBuffer.insertNode(data, m_uiC_StackPointer);
        m_uiC_StackPointer++;    
    }
    else
    {
        cout << "Stack full" << endl;
    }
}

template<class T>
void C_Stack<T>::pop()
{
    if(!this->isEmpty())
    {
        m_C_StackBuffer.deleteNode(m_uiC_StackPointer - 1);
        m_uiC_StackPointer--;
    }
    else
    {
        cout << "Stack empty already!" << endl;
    }
}

template<class T>
T C_Stack<T>::top()
{
    if(!this->isEmpty())
    {
        return m_C_StackBuffer.at(m_uiC_StackPointer - 1);
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}

template<class T>
bool C_Stack<T>::isEmpty()
{
    return (m_uiC_StackPointer == 0);
}
