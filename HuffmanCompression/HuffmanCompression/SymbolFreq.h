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
	void m_OpenFile(std::string name, std::vector<char>* temp);
	void m_OrderFrequencies(std::map<char, int>* unorderedSymbols);

public:
	//Constructos/destructors
	SymbolFreq();
	SymbolFreq(std::string name);

	~SymbolFreq();

	//Methods
	void PrintCharacterFreq();
	std::vector<std::pair<char, int>>* getFrequencies();
};
