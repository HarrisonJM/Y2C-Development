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

bool Rows::CheckAllCellsForCorrect() //TODO: pass to higher level or someshit I dunno
{
	return Areas::CheckAllCellsForCorrect();
}

bool Rows::CheckAllCellsForZero()
{
	return Areas::CheckAllCellsForZero();
}
