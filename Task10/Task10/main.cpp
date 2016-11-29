// LinkedList.cpp : Defines the entry point for the console application.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	linkedList aList;
	aList.insert(8);
	aList.insert(3);
	aList.insert(2);
	aList.insert(5);
	aList.update(2, 9);
	aList.update(8, 9);
	aList.update(5, 9);
	aList.update(3, 9);

	if (aList.remove(3))
	{
		cout << "Item successfully removed" << endl;
	}



	return 0;
}

