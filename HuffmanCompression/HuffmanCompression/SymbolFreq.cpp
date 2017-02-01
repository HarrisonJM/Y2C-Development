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
	std::vector<char>* temp = new std::vector<char>; //tempvector
	std::map<char, int>* unorderedSymbols = new std::map<char, int>;

	OpenFile(name, temp);

	pairs = new std::vector<std::pair<char, int>>;

	std::pair<std::map<char, int>::iterator, bool> it; //iterator
	std::vector<char>::iterator vecit; //iterator for vector

	//for (int i = 0; i < temp->size(); ++i)
	for(vecit = temp->begin(); vecit != temp->end(); ++vecit)
	{
		it = unorderedSymbols->insert(pair<char, int>(*vecit, 1)); //get iterator pair for inserted symbol

		if (it.second == false) //if the symbol already exists, increment
		{
			unorderedSymbols->at(*vecit) += 1;
		}
	}

	delete temp;

	orderFrequencies(unorderedSymbols); //re-order the frequencies, descending second value
	delete unorderedSymbols;

	PrintCharacterFreq();
}

SymbolFreq::~SymbolFreq()
{
	delete pairs;
}

//opens file at name and copies each char one by one into a vector
void SymbolFreq::OpenFile(string name, std::vector<char>* temp)
{
	char ch; 

	fstream infile(name, fstream::in);

	while(infile >> noskipws >> ch)
	{
		temp->push_back(ch); 
	}
}

//Moves map into a vector<pair> and then sorts 
void SymbolFreq::orderFrequencies(std::map<char, int>* unorderedSymbols)
{
	std::map<char, int>::iterator it;

	std::vector<std::pair<char, int>>::iterator vbeg; //pairs.begin()
	std::vector<std::pair<char, int>>::iterator vend; //pairs.end()

	//iterate over unordered symbols map
	for (it = unorderedSymbols->begin(); it != unorderedSymbols->end(); ++it)
	{
		pairs->push_back(*it); //add counted symbols to a vector of pairs
	}

	vbeg = pairs->begin();
	vend = pairs->end();

	sort(vbeg, vend, compare); //sort symbols based on value, descending
	//The order of symbols with the same value doesn't matter as they should have the same bit lengths

}

//prints frequencies in order of frequency
void SymbolFreq::PrintCharacterFreq()
{
	std::vector<std::pair<char, int>>::iterator it; //vector of pairs

	//for (int i = 0; i < pairs.size(); ++i)
	for(it = pairs->begin(); it != pairs->end(); ++it)
	{
		cout << it->first << "     " << it->second << endl;
	}
}

//return vector of pairs for later use
std::vector<std::pair<char, int>>* SymbolFreq::getFrequencies()
{
	return pairs;
}
