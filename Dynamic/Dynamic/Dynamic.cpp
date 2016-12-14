// Dynamic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "stats.h"

using namespace std;

int main()
{
	// ensure you convert the following to use dynamic memory instead of automatic memory
	stats s;
	s.getScores();

	cout << endl << "Average score is " << s.findAverage() << endl;

	return 0;
}

