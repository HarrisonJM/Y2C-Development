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
	vector<string> dissassProgram; //dissassembled program

public:
	SimpleTron();
	SimpleTron(string file);
	~SimpleTron();

	vector<string> SimpleTron::DisassembleProgram();
	void LoadProgramIntoMemoryFromFile(string file);

	void setProgramName(string name);

	vector<string> getDissassembledProgram();
	void DisplayDissassembledProgram();
	void SaveDissassemblyIntoFile();
};