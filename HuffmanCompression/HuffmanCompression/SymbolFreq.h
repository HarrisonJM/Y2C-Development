#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>    // std::sort
#include <functional>

using namespace std;

class SymbolFreq
{
private:
	std::vector<char> chars;
	std::vector<std::pair<char, int>> pairs; //vector of pairs
	std::map<char, int> unorderedSymbols;

public:

	SymbolFreq();
	SymbolFreq(std::string name);

	~SymbolFreq();

	std::vector<char> OpenFile(std::string name);
	void orderFrequencies();

	void PrintCharacterFreq();

	bool sortcomp(const pair<char, int> &a, const pair<char, int> &b);

	std::vector<std::pair<char, int>> getFrequencies();
};
