#pragma once

#include "Board.h"
#include "Areas.h"

class Zone : public Areas
{
private:
	Cell cells[3][3];

public:
	Zone();
	Zone(Board b, int position);

	~Zone();

	//virtual Cell AccessCells(int xpos, int ypos);
	Cell* AccessCells(int xpos, int ypos);

	virtual bool CheckAllCellsForCorrect(); //Makes sure there are no duplicates
	virtual bool CheckAllCellsForZero(); //Checks for empty spaces
};
