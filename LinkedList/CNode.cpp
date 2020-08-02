#include "CNode.h"

// Node define
template<class T>
inline CNode<T>::CNode()
{
	m_pNext = nullptr;
	m_Tdata = 0;
}

template<class T>
inline CNode<T>::CNode(T data)
{
	m_pNext = nullptr;
    m_Tdata = data;
}


template<class T>
inline void CNode<T>::SetNext(CNode *newNode)
{
	m_pNext = newNode;
}

template<class T>
inline void CNode<T>::SetData(T data)
{
	m_Tdata = data;
}

template<class T>
inline T CNode<T>::GetData()
{
	return m_Tdata;
}

template<class T>
inline CNode<T> * CNode<T>::GetNext()
{
	return m_pNext;
}

template class CNode<unsigned int>;