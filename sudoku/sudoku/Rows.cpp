#include "Rows.h"

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
	return Areas::CheckAllCellsForCorrect();
}

bool Rows::CheckAllCellsForZero()
{
	return Areas::CheckAllCellsForZero();
}
