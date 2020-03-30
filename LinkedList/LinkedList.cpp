/*
* Date : 04/10/2019
* Author: Minh Hieu
* Name of project: My linkedlish
*/

#include "LinkedList.h"

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
	CNode<T> *p_nextNode = NULL;
	for (unsigned int i = 0; i < m_uiNumberOfNode; i++)
	{
		p_nextNode = p_currentNode->GetNext();
		delete p_currentNode;
		p_currentNode = p_nextNode;
	}
}

template<class T>
inline void C_LinkedList<T>::insert(T newData, unsigned int uiPosition)
{
	CNode<T> *pNewNode = new CNode<T>;
	pNewNode->SetData(newData);
	pNewNode->SetNext(NULL);
	if((uiPosition == 1) || (m_pHead == NULL))
	{
		pNewNode->SetNext(m_pHead);
		m_pHead = pNewNode;
		m_uiNumberOfNode++;
		return;
	}

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
inline void C_LinkedList<T>::erase(unsigned int uiPosition)
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
	CNode<T> *currentNode = m_pHead;
	while (currentNode != NULL)
	{
		cout << currentNode->GetData() << " ";
		currentNode = currentNode->GetNext();
	}
	cout << endl;
}

template<class T>
inline T C_LinkedList<T>::at(unsigned int position)
{
	if (position >= m_uiNumberOfNode)
	{
		cout << "The List has only " << m_uiNumberOfNode << "elements" << endl;
	}
	else
	{
		CNode<T> *p_currentNode = m_pHead;
		for (unsigned int i = m_uiNumberOfNode; i > 0; i--)
		{
			if ((i - 1) == position)
				return p_currentNode->GetData();
			else
			{
				p_currentNode = p_currentNode->GetNext();
			}
		}
	}
}

template<class T>
inline unsigned int C_LinkedList<T>::size()
{
	return m_uiNumberOfNode;
}

