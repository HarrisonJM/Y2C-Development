// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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

	if (aList.remove(3))
	{
		cout << "Item successfully removed" << endl;
	}

	return 0;
}

