#include "Row.h"

Rows::Rows()
{

}

Rows::Rows(Board b, int position)
{
	vector<vector<Cell>> board = b.getBoard();

	for (int i = 0; i < 9; ++i)
	{
		cells[i] = board[i][position];
	}
}

Rows::~Rows()
{
}

bool Rows::CheckAllCellsForCorrect()
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

bool Rows::CheckAllCellsForZero()
{
	for (int i = 0; i < 9; ++i) //hold value to compare
	{
		if (cells[i].getCellVal() == 0) //empty cell present
		{
			return false;
		}
	}

	return true;
}
