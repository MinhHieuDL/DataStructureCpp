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
inline void C_LinkedList<T>::insert(T newData)
{
	CNode<T> *newNode = new CNode<T>;
	newNode->SetData(newData);
	newNode->SetNext(m_pHead);
	m_pHead = newNode;
	m_uiNumberOfNode++;
}

template<class T>
inline void C_LinkedList<T>::erase(T SearchingData)
{
	if (!m_pHead)
	{
		cout << "The List is currently empty" << endl;
	}
	else
	{
		CNode<T> *currentNode = m_pHead;
		CNode<T> *previousNode = NULL;
		for (unsigned int i = 0; i < m_uiNumberOfNode; i++)
		{
			if (currentNode->GetData() == SearchingData)
			{
				previousNode->SetNext(currentNode->GetNext());
				delete currentNode;
				return;
			}
			else
			{
				previousNode = currentNode;
				currentNode = currentNode->GetNext();
			}
		}
		cout << "The object you want to remove doesn't exist in List" << endl;
	}
}

template<class T>
inline void C_LinkedList<T>::display()
{
	CNode<T> *currentNode = m_pHead;
	for (unsigned int i = 0; i < m_uiNumberOfNode; i++)
	{
		cout << currentNode->GetData() << endl;
		currentNode = currentNode->GetNext();
	}
}

template<class T>
inline T C_LinkedList<T>::at(unsigned int position)
{
	CNode<T> *returnNode = NULL;
	if (position >= m_uiNumberOfNode)
	{
		cout << "The List has only" << m_uiNumberOfNode << "elements" << endl;
	}
	else
	{
		CNode<T> *currentNode = m_pHead;
		for (unsigned int i = m_uiNumberOfNode; i > 0; i--)
		{
			if ((i - 1) == position)
				return currentNode->GetData();
			else
			{
				currentNode = currentNode->GetNext();
			}
		}
	}
}

template<class T>
inline unsigned int C_LinkedList<T>::size()
{
	return m_uiNumberOfNode;
}

