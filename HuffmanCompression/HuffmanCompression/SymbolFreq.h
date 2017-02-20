#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>    // std::sort
#include <functional>

/// <summary>
/// Class:			SymbolFreq
/// Description:	When supplied with a file name, will store, count and sort,
/// 				the symbols in that file for use later on in the Hoffman compression
/// Constructors:	Default: Does nothing don't use
/// 				SymbolFreq(std::string name): name is file path, always use this
/// 
/// Methods:		PrintChracterFreq();
/// 				getFrequencies();
/// </summary>
class SymbolFreq
{
private:
	//Member variables
	std::vector<std::pair<char, int>>* pairs;

	//Member Functions
	void OpenFile(std::string name, std::vector<char>* temp);
	void orderFrequencies(std::map<char, int>* unorderedSymbols);

public:

	SymbolFreq();
	SymbolFreq(std::string name);

	~SymbolFreq();

	void PrintCharacterFreq();

	std::vector<std::pair<char, int>>* getFrequencies();
};
