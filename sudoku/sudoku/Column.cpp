#include "Column.h"

Column::Column()
{
}

Column::Column(Board b, int position)
{
	vector<vector<Cell>> board = b.getBoard();

	for (int i = 0; i < 9; ++i)
	{
		cells[i] = board[position][i];
	}
}

Column::~Column()
{
}

Cell* Column::AccessCells(int xpos, int ypos)
{
	return &cells[xpos];
}

//This method can be duplicated/improved by accepting an index and only hcecking against that
bool Column::CheckAllCellsForCorrect() //TRUE = cells correct, FALSE = duplicates
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

				if (cells[i].getCellVal() > 9) //too big
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool Column::CheckAllCellsForZero()
{
	for (int i = 0; i < 9; ++i)
	{
		if (cells[i].getCellVal() == 0) //empty cell present
		{
			return false; //False for 0/empty cell
		}
	}

	return true; //true if no 0's present;
}

