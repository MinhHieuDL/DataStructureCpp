/*
* Date : 25/07/2020
* Author: Minh Hieu
* Name of project: My Stack DS
*/

#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
    m_uiStackPointer = 0;
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
    m_StackBuffer.insertNode(data, m_uiStackPointer);
    m_uiStackPointer++;
}

template<class T>
void Stack<T>::pop()
{
    if(!this->isEmpty())
    {
        m_StackBuffer.deleteNode(m_uiStackPointer);
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
        return m_StackBuffer.at(m_uiStackPointer);
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
