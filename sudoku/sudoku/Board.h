#pragma once

#include "Cell.h"
#include "Main.h"
#include <string>

using namespace std;

class Board
{
private:
	Cell cells[GRIDSIZE][GRIDSIZE];

public:
	Board();
	~Board();

	void populateBoard(string name, Board board);
	void PrintBoard();
};
