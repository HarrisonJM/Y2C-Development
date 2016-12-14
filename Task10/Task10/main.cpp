// main.cpp : Defines the entry point for the console application.
//

//************************************************************//
// Sorry I didn't get around to experimenting further. When I 
//had the time I went straight into the sudoku task and some other
//projects I have on the go.

#include "LinkedBunnies.h"
#include <iostream>
using namespace std;

int main()
{
	int deleted;

	LinkedBunnies Herd;
	Herd.insert(8);
	Herd.insert(3);
	Herd.insert(2);
	Herd.insert(5);
	Herd.insert(5);

	Herd.updateAge(8, 9);
	Herd.updateAge(3, 9);
	Herd.updateAge(2, 9);
	Herd.updateAge(5, 9);

	Herd.updateAllAge(9, 5);
	Herd.updateAge(5, 8);

	Herd.AgeBunnies();

	if (Herd.remove(6))
	{
		cout << "Item successfully removed" << endl;
	}

	return 0;
}

