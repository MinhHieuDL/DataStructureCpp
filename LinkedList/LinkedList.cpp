/*
* Date : 04/10/2019
* Author: Minh Hieu
* Name of project: My linkedlish
*/

#include "LinkedList.h"
#define USING_RECURSIVE
// Node define
template<class T>
inline CNode<T>::CNode()
{
	m_pNext = NULL;
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

// List Define
template<class T>
inline C_LinkedList<T>::C_LinkedList()
{
	m_pHead = NULL;
	m_uiNumberOfNode = 0;
}

template<class T>
C_LinkedList<T>::~C_LinkedList()
{
	CNode<T> *p_currentNode = m_pHead;
	CNode<T> *pNextNode = NULL;
	for (unsigned int i = 0; i < m_uiNumberOfNode; i++)
	{
		pNextNode = p_currentNode->GetNext();
		delete p_currentNode;
		p_currentNode = pNextNode;
	}
}

template<class T>
inline void C_LinkedList<T>::insertNode(T newData, unsigned int uiPosition)
{
	CNode<T> *pNewNode = new CNode<T>;
	pNewNode->SetData(newData);
	pNewNode->SetNext(NULL);
	// add the new node to the head of the linked list
	if((uiPosition == 1) || (m_pHead == NULL))
	{
		pNewNode->SetNext(m_pHead);
		m_pHead = pNewNode;
		m_uiNumberOfNode++;
		return;
	}
	// add the new node to the tail of the linked list if the position > last position of the list
	if(uiPosition > m_uiNumberOfNode + 2)
	{
		uiPosition = m_uiNumberOfNode + 1;
	}
	// add the new node to the any position of the linked list
	CNode<T> *pCurrentNode = m_pHead;
	for(unsigned int i = 0; i < uiPosition - 2; i++)
	{
		pCurrentNode = pCurrentNode->GetNext();
	}
	pNewNode->SetNext(pCurrentNode->GetNext()); 
	pCurrentNode->SetNext(pNewNode);
	m_uiNumberOfNode++;
}

template<class T>
inline void C_LinkedList<T>::deleteNode(unsigned int uiPosition)
{
	if (!m_pHead)
	{
		cout << "The List is currently empty" << endl;
	}
	else
	{	
		CNode<T> *pPrevNode = m_pHead;
		if(uiPosition == 1)
		{
			m_pHead = pPrevNode->GetNext();
			delete pPrevNode;
			m_uiNumberOfNode--;
			return;
		}
		for(unsigned int i = 0; i < uiPosition - 2; i++)
		{
			pPrevNode = pPrevNode->GetNext();
		}
		CNode<T> *pCurrentNode = pPrevNode->GetNext();
		pPrevNode->SetNext(pCurrentNode->GetNext());
		delete pCurrentNode;
		m_uiNumberOfNode--;
	}
}

template<class T>
inline void C_LinkedList<T>::display()
{
#ifndef USING_RECURSIVE
	CNode<T> *pCurrentNode = m_pHead;
	while (pCurrentNode != NULL)
	{
		cout << pCurrentNode->GetData() << " ";
		pCurrentNode = pCurrentNode->GetNext();
	}
	cout << endl;
#else
	cout << "This list was displayed using recursive:";
	displayRecursive(m_pHead);
#endif
}

template<class T>
inline void C_LinkedList<T>::displayRecursive(CNode<T> *pNode)
{
	if(pNode == NULL)
	{
		cout << endl;
		return;
	}
	cout << pNode->GetData() << " ";
	displayRecursive(pNode->GetNext());
}

template<class T>
inline void C_LinkedList<T>::reverse()
{
#ifndef USING_RECURSIVE
	CNode<T> *pPrevNode = NULL;
	CNode<T> *pCurNode = m_pHead;
	CNode<T> *pNextNode = NULL;
	while (pCurNode != NULL)
	{
		pNextNode = pCurNode->GetNext();
		pCurNode->SetNext(pPrevNode);
		pPrevNode = pCurNode;
		pCurNode = pNextNode;
	}
	m_pHead = pPrevNode;
#else
	cout << "This list was reversed using the recursive!" << endl;
	reverseRecursive(m_pHead);
#endif
}

template<class T>
inline void C_LinkedList<T>::reverseRecursive(CNode<T> *pNode)
{
	if(pNode->GetNext() == NULL)
	{
		m_pHead = pNode;
		return;
	}
	reverseRecursive(pNode->GetNext());
	CNode<T> *pNextNode = pNode->GetNext();
	pNextNode->SetNext(pNode);
	pNode->SetNext(NULL);
}

template<class T>
inline T C_LinkedList<T>::at(unsigned int uiPosition)
{
	T ret = 0;
	if (uiPosition > m_uiNumberOfNode)
	{
		cout << "The List has only " << m_uiNumberOfNode << " elements" << endl;
	}
	else
	{
		CNode<T> *p_currentNode = m_pHead;
		
		if(uiPosition != 1)
		{
			for (unsigned int i = 0; i < uiPosition - 1; i++)
			{
				p_currentNode = p_currentNode->GetNext();
			}
		}
		ret = p_currentNode->GetData();
	}
	return ret;
}

template<class T>
inline unsigned int C_LinkedList<T>::size()
{
	return m_uiNumberOfNode;
}

