//#include "Stack.h"
//#include "Stack.cpp"
#include "LinkedList.h"
#include "Stack.h"
//#include "LinkedList.cpp"
int main(void)
{
	//C_LinkedList<unsigned int> TestList;
	//TestList.insertNode(1, 1);
	//TestList.insertNode(2, 3);
	//TestList.insertNode(3, 2);
	//TestList.display();

	C_Stack<unsigned int> TestStack(5);
	for(unsigned i = 0; i < 5; i++)
	{
		TestStack.push(i);
	}

	for(unsigned i = 0; i < 5; i++)
	{
		cout << TestStack.top() << endl;
		TestStack.pop();
	}
	cin.get();
	return 0;
}