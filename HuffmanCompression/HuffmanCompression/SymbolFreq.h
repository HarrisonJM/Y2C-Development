#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>    // std::sort
#include <functional>

using namespace std;

/*
	Class:			SymbolFreq
	Description:	When supplied with a file name, will store, count and sort,
					the symbols in that file for use later on in the Hoffman compression
	Constructors:	Default: Does nothing don't use
					SymbolFreq(std::string name): Should always be used
*/
class SymbolFreq
{
private:
	//Member variables
	std::vector<char> chars;
	std::vector<std::pair<char, int>> pairs; //vector of pairs
	std::map<char, int> unorderedSymbols;

	//Member Functions
	std::vector<char> OpenFile(std::string name);
	void orderFrequencies();

public:

	SymbolFreq();
	SymbolFreq(std::string name);

	~SymbolFreq();

	void PrintCharacterFreq();

	std::vector<std::pair<char, int>> getFrequencies();
};
