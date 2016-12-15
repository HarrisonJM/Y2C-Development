#pragma once

#include "Board.h"
#include "Areas.h"

class Rows : public Areas
{
private:
	Cell cells[9];

public:
	Rows();
	Rows(Board board, int position);

	~Rows();

	virtual bool CheckAllCellsForCorrect(); //Makes sure there are no duplicates
	virtual bool CheckAllCellsForZero(); //Checks for empty spaces
};

