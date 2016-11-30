// LinkedList.cpp : Defines the entry point for the console application.
//

#include "LinkedBunnies.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedBunnies Herd;
	//Herd.insert(8);
	//Herd.insert(3);
	//Herd.insert(2);
	//Herd.insert(5);
	//Herd.update(2, 9);
	//Herd.update(8, 9);
	//Herd.update(5, 9);
	//Herd.update(3, 9);

	if (Herd.remove(3))
	{
		cout << "Item successfully removed" << endl;
	}



	return 0;
}

