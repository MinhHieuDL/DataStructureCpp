#ifndef _CNode_H
#define _CNode_H

using namespace std;

template<class T>
class CNode
{
private:
	T m_Tdata;
	CNode<T> *m_pNext;
public:
	CNode();
    	CNode(T data);
	void SetData(T data);
	T GetData();
	void SetNext(CNode<T> *);
	CNode<T>* GetNext(void);
};
#endif
