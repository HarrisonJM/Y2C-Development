#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>

#include "SymbolFreq.h"
#include "BinTree.h"
#include "HuffmanCodeTree.h"

/*
	Class: Source
	Description: Generic header for source.cpp
*/

void writetofile(std::vector<std::pair<char, int>>* things);
std::vector<std::pair<char, int>>* readfromfile();

class Source
{
private:
	
public:

};
