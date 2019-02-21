#include "LinkedList.h"
#include "LinkedList.cpp"
#include <string>

int main(void)
{
	string Name[3] = { "DLSVN1","DLSVN2" ,"DLSVN3" };
	C_LinkedList<string> ListName;
	for (unsigned i = 0; i < 3; i++)
	{
		ListName.insert(Name[i]);
	}
	for (unsigned int i = 0; i < ListName.size(); i++)
	{
		cout << ListName.at(i) << endl;
	}
	ListName.erase("DLSVN2");
	cout << "The size of List is: " << ListName.size() << endl;
	ListName.erase("DLSVN2");
	cin.get();
	return 0;
}