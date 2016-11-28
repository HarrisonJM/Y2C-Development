#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

#include "SimpleTron.h"

SimpleTron::SimpleTron()
{
}

SimpleTron::~SimpleTron()
{
}

vector<string> SimpleTron::DisassembleProgram()
{

}

void SimpleTron::loadProgramIntoMemory(string file)
{
	ifstream infile(file);
	string line;
	vector<string> programLines;

	while (getline(infile, line))
	{
		program.push_back(line);
	}

	for (int i = 0; i < programLines.size(); i++)
	{
		cout << program[i] << endl;;
	}
}
