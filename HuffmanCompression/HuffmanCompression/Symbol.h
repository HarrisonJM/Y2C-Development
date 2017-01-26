#pragma once

#include <map>

class Symbol
{
private:
	char sym;
	int freq;

public:

	Symbol();
	Symbol(char sym);
	Symbol(std::pair<char, int> p);

	~Symbol();

	char getSym();
	void setSym(char sym);

	int getFreq();
	void setFreq(int freq);
	void incrementFreq();
};
