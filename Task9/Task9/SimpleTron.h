#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

using namespace std;


class SimpleTron
{
private:
	string programName;
	vector<string> program;

public:
	SimpleTron();
	~SimpleTron();

	vector<string> SimpleTron::DisassembleProgram();
	void loadProgramIntoMemory(string file);
};