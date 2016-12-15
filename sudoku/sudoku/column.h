#pragma once

#include "Board.h"
#include "Areas.h"

class Column : public Areas
{
private:
	Cell cells[9];

public:
	Column();
	Column(Board b, int position);

	~Column();

	virtual bool CheckAllCellsForCorrect(); //Makes sure there are no duplicates
	virtual bool CheckAllCellsForZero(); //Checks for empty spaces
};
