#include "SymbolFreq.h"

using namespace std;

//Operation Functor used for sort() function
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
	return i.second > j.second;
}

//Default Constructor
SymbolFreq::SymbolFreq()
{

}

//counts all symbols
SymbolFreq::SymbolFreq(std::string name)
{
	vector<char> temp = OpenFile(name); //tempvector
	std::pair<std::map<char, int>::iterator, bool> it; //iterator

	for (int i = 0; i < temp.size(); ++i)
	{
		it = unorderedSymbols.insert(pair<char, int>(temp[i], 1)); //get iterator pair for inserted symbol

		if (it.second == false) //if the symbol already exists, increment
		{
			unorderedSymbols[temp[i]] += 1;
		}
	}

	orderFrequencies(); //re-order the frequencies, descending second value

	PrintCharacterFreq();
}

SymbolFreq::~SymbolFreq()
{

}

//opens file at name and copies each char one by one into a vector
std::vector<char> SymbolFreq::OpenFile(string name)
{
	std::vector<char> temp;
	char ch; 

	fstream infile(name, fstream::in);

	while(infile >> noskipws >> ch)
	{
		temp.push_back(ch); 
	}

	return temp; //return vector of symbols
}

//Sorts symbols by order of frequency
void SymbolFreq::orderFrequencies()
{
	std::map<char, int>::iterator it;

	//iterate over unordered symbols map
	for (it = unorderedSymbols.begin(); it != unorderedSymbols.end(); ++it)
	{
		pairs.push_back(*it); //add counted symbols to a vector of pairs
	}

	sort(pairs.begin(), pairs.end(), compare); //sort symbols based on value, descending

}

//prints frequencies in order of frequency
void SymbolFreq::PrintCharacterFreq()
{
	for (int i = 0; i < pairs.size(); ++i)
	{
		cout << pairs[i].first << "     " << pairs[i].second << endl;
	}
}

//return vector of pairs for later use
std::vector<std::pair<char, int>> SymbolFreq::getFrequencies()
{
	return pairs;
}
