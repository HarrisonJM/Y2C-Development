#include "SymbolFreq.h"

using namespace std;

/// <summary>
/// Functor used for sort() function
/// </summary>
/// <param name="i"></param>
/// <param name="j"></param>
/// <returns></returns>
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
	return i.second > j.second;
}

/// <summary>
/// 
/// </summary>
SymbolFreq::SymbolFreq()
{

}

/// <summary>
/// Constructor, opens a file, counts and orders the characters
/// </summary>
/// <param name="name"></param>
SymbolFreq::SymbolFreq(std::string name)
{
	std::vector<char>* temp = new std::vector<char>; //tempvector
	std::map<char, int>* unorderedSymbols = new std::map<char, int>;

	m_OpenFile(name, temp);

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

	m_OrderFrequencies(unorderedSymbols); //re-order the frequencies, descending second value

	delete unorderedSymbols;
	delete temp;

	PrintCharacterFreq();
}

SymbolFreq::~SymbolFreq()
{
	delete pairs;
}

/// <summary>
/// opens file at name and copies each char one by one into a vector
/// </summary>
/// <param name="name"></param>
/// <param name="temp"></param>
void SymbolFreq::m_OpenFile(string name, std::vector<char>* temp)
{
	char ch; 

	fstream infile(name, fstream::in);

	while(infile >> noskipws >> ch)
	{
		temp->push_back(ch); 
	}
}

/// <summary>
/// Orders all frequencies in vector from largest count to lowest, descending
/// </summary>
/// <param name="unorderedSymbols"></param>
void SymbolFreq::m_OrderFrequencies(std::map<char, int>* unorderedSymbols)
{
	std::map<char, int>::iterator it;

	std::vector<std::pair<char, int>>::iterator vbeg; //pairs.begin()
	std::vector<std::pair<char, int>>::iterator vend; //pairs.end()

	//iterate over unordered symbols map
	for (it = unorderedSymbols->begin(); it != unorderedSymbols->end(); ++it)
	{
		pairs->push_back(*it); //add counted symbols to a vector of pairs
	}

	vbeg = pairs->begin(); //strange error, had to explicitly set them to iterators, even thoguh they are
	vend = pairs->end();

	sort(vbeg, vend, compare); //sort symbols based on value, descending
	//The order of symbols with the same value doesn't matter as they should have the same bit lengths

}

/// <summary>
/// prints frequencies in order of frequency
/// </summary>
void SymbolFreq::PrintCharacterFreq()
{
	std::vector<std::pair<char, int>>::iterator it; //vector of pairs

	for(it = pairs->begin(); it != pairs->end(); ++it)
	{
		cout << it->first << "     " << it->second << endl;
	}
}

/// <summary>
/// returns the symbols and their frequencies for alter use as a vector of pairs
/// </summary>
/// <returns></returns>
std::vector<std::pair<char, int>>* SymbolFreq::getFrequencies()
{
	return pairs;
}
