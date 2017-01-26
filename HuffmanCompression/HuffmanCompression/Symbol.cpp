#include "Symbol.h"

Symbol::Symbol()
{

}

Symbol::Symbol(char sym)
{
	this->sym = sym;
	//freq = 0;
}

Symbol::Symbol(std::pair<char, int> p)
{
	this->sym = p.first;
	this->freq = p.second;
}

Symbol::~Symbol()
{
}

char Symbol::getSym()
{
	return sym;
}

void Symbol::setSym(char sym)
{
	this->sym = sym;
}



int Symbol::getFreq()
{
	return freq;
}

void Symbol::setFreq(int freq)
{
	this->freq = freq;
}

void Symbol::incrementFreq()
{
	freq++;
}
