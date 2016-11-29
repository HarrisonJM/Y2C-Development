#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

#include "SimpleTron.h"

#define FILENAME "program.txt"

using namespace std;

int main()
{
	string programName;

	cout << "welcome to the Simpletron Dissassembler!" << endl;
	cout << "Enter name of file to dissassemble! (type program.txt for default)" << endl;
	cin >> programName;
	//programName = "program.txt"; //MUST REMOVE
	
	cout << "You have entered: " << programName << endl;

	SimpleTron ST(programName);

	cout << "Program Loaded. Dissassembling..." << endl;
	ST.DisassembleProgram();

	cout << "Program Dissassembled! Displaying..." << endl;


	ST.DisplayDissassembledProgram();
	ST.SaveDissassemblyIntoFile();

	system("pause");

	return 0;
}

