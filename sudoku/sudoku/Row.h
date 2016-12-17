#pragma once

#include "Board.h"
#include "Areas.h"

class Row : public Areas
{
private:
	Cell cells[9];

public:
	Row();
	Row(Board board, int position);

	~Row();

	//virtual Cell AccessCells(int xpos, int ypos);
	Cell AccessCells(int xpos, int ypos);

	virtual bool CheckAllCellsForCorrect(); //Makes sure there are no duplicates
	virtual bool CheckAllCellsForZero(); //Checks for empty spaces
};

