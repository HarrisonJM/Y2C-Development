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

bool Column::CheckAllCellsForCorrect()
{
	return Areas::CheckAllCellsForCorrect();
}

bool Column::CheckAllCellsForZero()
{
	return Areas::CheckAllCellsForZero();
}
