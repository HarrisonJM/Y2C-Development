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

SimpleTron::SimpleTron(string file)
{
	programName = file;
	LoadProgramIntoMemoryFromFile(file);

}

SimpleTron::~SimpleTron()
{

}

vector<string> SimpleTron::DisassembleProgram()
{
	string tempopcode, tempval;
	int opcode, value;

	// = s1.substr(1, 7); // this produces the result you asked for "ello, w" 

	for (int i = 0; i < program.size(); ++i)
	{
		tempopcode = program[i].substr(0, 2);
		opcode = stoi(tempopcode, 0);

		tempval = program[i].substr(2, 3);
		value = stoi(tempval, 0);

		dissassProgram.push_back("");

		if ((i < 10))
		{
			dissassProgram[i] = "0" + to_string(i) + " : " + " (" + program[i] + ")" + ": ";
		}

		//dissassProgram
		switch (opcode)
		{
		case 10:
			dissassProgram[i] += "READ into" + to_string(value);
			break;

		case 11:
			dissassProgram[i] += "WRITE " + to_string(value) + " into CONSOLE";
			break;

		case 20:
			dissassProgram[i] += "LOAD " + to_string(value) + " into Acc;";
			break;

		case 21:
			dissassProgram[i] += "STORE Acc. into" + to_string(value);
			break;

		case 30:
			dissassProgram[i] += "ADD to acc from value at " + to_string(value);
			break;

		case 31:
			dissassProgram[i] += "SUB acc by value at " + to_string(value);
			break;

		case 32:
			dissassProgram[i] += "MUL by acc by value at " + to_string(value);
			break;

		case 33:
			dissassProgram[i] += "DIV acc by value at " + to_string(value);
			break;

		case 40:
			dissassProgram[i] += "JUMP if (continue running program from) " + to_string(value);
			break;

		case 41:
			dissassProgram[i] += "JUMPIFNEG if negative " + to_string(value);
			break;

		case 42:
			dissassProgram[i] += "JUMPIFZERO to " + to_string(value);
			break;

		case 43:
			dissassProgram[i] += "HALT";;
			break;
		default:
			dissassProgram[i] += "ERROR: INVALID OPCODE!";
			break;
		}

		dissassProgram[i] += '\n';
	}

	return dissassProgram;
}

void SimpleTron::LoadProgramIntoMemoryFromFile(string file)
{
	ifstream infile(file);
	string line;
	vector<string> programLines;

	while (getline(infile, line))
	{
		program.push_back(line);
	}

	for (int i = 0; i < program.size(); ++i)
	{
		if (i == 100)
		{
			cout << "ERROR: MAX SIZE 100! Decompiling first 100 instructions." << endl;
			break;
		}
		cout << program[i] << endl;
	}
}

void SimpleTron::setProgramName(string name)
{
	programName = name;
}

vector<string> SimpleTron::getDissassembledProgram()
{
	return dissassProgram;
}

void SimpleTron::DisplayDissassembledProgram()
{
	for (int i = 0; i < dissassProgram.size(); ++i)
	{
		cout << dissassProgram[i];
	}
}

void SimpleTron::SaveDissassemblyIntoFile()
{
	ofstream outfile;
	outfile.open("dissassembledProgram.txt");
	cout << "Saving to file" << endl;

	for (int i = 0; i < dissassProgram.size(); ++i)
	{
		outfile << dissassProgram[i];
	}

	outfile.close();
}
