#pragma once

#include "Cell.h"
#include "Main.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

class Board
{
private:
	//int cells[GRIDSIZE][GRIDSIZE];
	vector<vector<int>> cells;

public:
	Board();
	Board(string name);
	~Board();

	void populateBoard(string name);
	void PrintBoard();
	vector<vector<int>> getBoard();
};
