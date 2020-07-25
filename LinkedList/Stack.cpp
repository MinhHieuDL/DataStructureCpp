/*
* Date : 25/07/2020
* Author: Minh Hieu
* Name of project: My Stack DS
*/

#include "Stack.h"

template<class T>
Stack<T>::Stack(unsigned int uiSize)
{
    m_uiStackPointer = 0;
    m_uiSize = uiSize;
}

template<class T>
Stack<T>::~Stack()
{
    while(!this->isEmpty())
    {
        this->pop();
    }
}

template<class T>
void Stack<T>::push(T data)
{
    if(m_uiStackPointer < m_uiSize)
    {
        m_StackBuffer.insertNode(data, m_uiStackPointer);
        m_uiStackPointer++;    
    }
    else
    {
        cout << "Stack full" << endl;
    }
}

template<class T>
void Stack<T>::pop()
{
    if(!this->isEmpty())
    {
        m_StackBuffer.deleteNode(m_uiStackPointer - 1);
        m_uiStackPointer--;
    }
    else
    {
        cout << "Stack empty already!" << endl;
    }
}

template<class T>
T Stack<T>::top()
{
    if(!this->isEmpty())
    {
        return m_StackBuffer.at(m_uiStackPointer - 1);
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}

template<class T>
bool Stack<T>::isEmpty()
{
    return (m_uiStackPointer == 0);
}
