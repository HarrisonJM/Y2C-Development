#include "Source.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

//Operation Functor used for sort() function
static bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
	return i.second > j.second;
}

int main(int argc, char* argv[])
{
	SymbolFreq* SF = new SymbolFreq("ToCompress.txt"); //Symbol Frequency object
	writetofile(SF->getFrequencies());

	delete SF;

	std::vector<std::pair<char, int>> *things;// = new std::vector<std::pair<char, int>>;
	things = readfromfile();

	BinTree* BT = new BinTree(things);
	BT->PrintTree();

	delete BT;

	HuffmanCodeTree *PQ = new HuffmanCodeTree(things);

	delete PQ;

	return 0;
}


//writes data to file for testing and use between different projects
void writetofile(std::vector<std::pair<char, int>>* things)
{
	std::vector<std::pair<char, int>>::iterator iter;
	ofstream outputfile("Data", ios::out, ios::binary);

	for (iter = things->begin(); iter != things->end(); ++iter)
	{
		outputfile << (int)iter->first << " " << iter->second << "\n";
	}
}

//reads a file into a vector of pairs for use in other areas of the program
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

		pa.first = (char)key;
		pa.second = value;

		vec->push_back(pa);
	}

	return vec;
}