#include "Zone.h"

Zone::Zone()
{
}

Zone::Zone(Board b, int position)
{
	int indexerx = 0;
	int indexery = 0;

	vector<vector<Cell>> board = b.getBoard();

	switch (position)
	{
	case 0: //top left
		indexerx = 0;
		indexery = 0;
		break;
	case 1: //top mid
		indexerx = 3;
		indexery = 0;
		break;
	case 2: //top right
		indexerx = 6;
		indexery = 0;
		break;
	case 3: //mid left
		indexerx = 0;
		indexery = 3;
		break;
	case 4: //true neutral
		indexerx = 3;
		indexery = 3;
		break;
	case 5: //mid right
		indexerx = 6;
		indexery = 3;
		break;
	case 6: //bottom left
		indexerx = 0;
		indexery = 6;
		break;
	case 7: //bottom mid
		indexerx = 3;
		indexery = 6;
		break;
	case 8: //bottom right
		indexerx = 6;
		indexery = 6;
		break;
	}

	for (int i = 0 + indexerx; i < 3 + indexerx; ++i)
	{
		for (int j = 0 + indexery; j < 3 + indexery; ++j)
		{
			cells[i - indexerx][j - indexery] = board[i][j];
		}
	}
}

Zone::~Zone()
{
}

bool Zone::CheckAllCellsForCorrect()
{
	for (int i = 0; i < 3; ++i) //hold value to compare
	{
		for (int j = 0; i < 3; ++i) //hold value to compare
		{
			for (int k = 0; k < 3; ++k) //iterate through values and compare
			{
				for (int l = 0; l < 3; ++l) //iterate through values and compare
				{
					if (((i - k) != 0) && ((j - l) != 0)) //same cell
					{
						if (cells[i][j].getCellVal() == 0) //whitespace
						{
							continue;
						}
						if (cells[i][j].getCellVal() == cells[k][l].getCellVal()) //duplicate cell
						{
							return false;
						}
					}
				}
			}
		}
	}
	
	return true;;
}

bool Zone::CheckAllCellsForZero()
{
	for (int i = 0; i < 3; ++i) //hold value to compare
	{
		for (int j = 0; j < 3; ++j) //hold value to compare
		{
			if (cells[i][j].getCellVal() == 0) //empty cell present
			{
				return false;
			}
		}
	}

	return true;
}
