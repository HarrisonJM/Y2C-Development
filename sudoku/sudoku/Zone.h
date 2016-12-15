#pragma once

#include "Board.h"

class Zone
{
private:
	int cells[3][3];

public:
	Zone();
	Zone(Board board, int position);

	~Zone();

	bool CheckAllCellsForCorrect(); //Makes sure there are no duplicates
	bool CheckAllCellsForZero();
};
