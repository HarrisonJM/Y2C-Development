#include "Areas.h"

bool Areas::CheckAllCellsForCorrect()
{
	for (int i = 0; i < GRIDSIZE; ++i)
	{
		for (int j = 0; j < GRIDSIZE; ++j)
		{
			if ((i - j) != 0) //same cell
			{
				if (cells[i].getCellVal() == 0) //whitespace
				{
					continue;
				}
				if (cells[i].getCellVal() == cells[j].getCellVal()) //duplicate cell
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool Areas::CheckAllCellsForZero()
{
	for (int i = 0; i < 3; ++i) //hold value to compare
	{
		if (cells[i].getCellVal() == 0) //empty cell present
		{
			return false;
		}
	}

	return true;
}

Cell Areas::AccessCells(int xpos, int ypos)
{
	return cells[xpos];
}
