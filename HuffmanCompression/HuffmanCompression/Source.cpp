#include "Source.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

/// <summary>
/// Main entry point for program
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char* argv[])
{
	SymbolFreq* SF = new SymbolFreq("ToCompress.txt"); //File that needs compressing
	writetofile(SF->getFrequencies()); //Write values to a file for testing purposes, i.e. other tasks

	delete SF;

	std::vector<std::pair<char, int>> *data;
	data = readfromfile(); //write testing file into vector

	BinTree* BT = new BinTree(data); //BinTree proof
	BT->PrintTree();

	delete BT;

	HuffmanCodeTree *PQ = new HuffmanCodeTree(data); //Binary tree developed with a priority queue
	PQ->PrintCodeTree();

	delete PQ;

	return 0;
}


/// <summary>
/// //writes data to file for testing and use between different projects
/// </summary>
/// <param name="data"></param>
void writetofile(std::vector<std::pair<char, int>>* data)
{
	std::vector<std::pair<char, int>>::iterator iter;
	ofstream outputfile("Data", ios::out, ios::binary);

	for (iter = data->begin(); iter != data->end(); ++iter)
	{
		//writes the characters to the file as numbers so that ' ' isn't ignored
		outputfile << (int)iter->first << " " << iter->second << "\n"; 
	}
}

/// <summary>
/// //reads a file into a vector of pairs for use in other areas of the program
/// </summary>
/// <returns> std::vector<std::pair<char, int>>* </returns>
std::vector<std::pair<char, int>>* readfromfile()
{	
	std::vector<std::pair<char, int>>* vec = new std::vector<std::pair<char, int>>;
	int key;
	int value;

	ifstream inputfile;
	inputfile.open("Data", ios::in);

	while (inputfile >> key >> value)
	{
		pair<char, int> pa;

		pa.first = (char)key; //chracters saved as ASCII code, so it needs casting
		pa.second = value;

		vec->push_back(pa);
	}

	return vec;
}