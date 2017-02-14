#include "Source.h"

using namespace std;

//Operation Functor used for sort() function
static bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
	return i.second > j.second;
}

int main(int argc, char* argv[])
{
	SymbolFreq* SF = new SymbolFreq("ToCompress.txt"); //Symbol Frequency object

	//delete SF;

	BinTree* BT = new BinTree(SF->getFrequencies());

	BT->PrintTree(BT->getRootNode());

	system("pause");

	return 0;
}