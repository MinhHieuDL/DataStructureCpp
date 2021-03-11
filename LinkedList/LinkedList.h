#ifndef _LinkedList_H
#define _LinkedList_H

#include <iostream>
#include "CNode.h"
using namespace std;

template<class T>
class C_LinkedList
{
private:
	CNode<T> *m_pHead;
	unsigned int m_uiNumberOfNode;
	void reverseRecursive(CNode<T> *pNode);
	void displayRecursive(CNode<T> *pNode);
public:
	C_LinkedList();
	~C_LinkedList();
	void insertNode(T, unsigned int);
	void deleteNode(unsigned int);
	void reverse();
	void display();
	T at(unsigned int);
	unsigned int size();
};
#endif // !LinkedList



