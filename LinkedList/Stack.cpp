/*
* Date : 25/07/2020
* Author: Minh Hieu
* Name of project: My C_Stack DS
*/

#include "Stack.h"
using namespace std;

template<class T>
C_Stack<T>::C_Stack(unsigned int uiSize)
{
    m_uiNumOfElements = 0;
    m_uiSize = uiSize;
    m_pStackNodePointer = nullptr;
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
    if(m_uiNumOfElements < m_uiSize)
    {
        CNode<T>* pNewNode = new CNode<T>(data);
        pNewNode->SetNext(m_pStackNodePointer);
        m_pStackNodePointer = pNewNode;
        m_uiNumOfElements++;    
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
        CNode<T>* pTempNode = m_pStackNodePointer->GetNext();
        delete m_pStackNodePointer;
        m_pStackNodePointer = pTempNode;
        m_uiNumOfElements--;
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
        return m_pStackNodePointer->GetData();
    }
    else
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
}

template<class T>
bool C_Stack<T>::isEmpty()
{
    return (m_uiNumOfElements == 0);
}

template class C_Stack<unsigned int>;