#include "Backtracking.h"
#include <iostream>

//while (empty cells exist in solution) 
//{
//		if (cell(row, col) is empty) 
//		{
//			assign the empty cell with a valid value(i)
//			one that does not exists in the same row,
//			column OR zone as the cell)
//
//			if (no valid value for (i) can be found) 
//			{
//				backtrack to previous solution
//				adjust col and row accordingly
//				remove assigned value from the previously updated cell
//				find another valid value(i) for this cell
//				if no valid value can be found
//				{
//					repeat the backtrack
//				}
//			}
//}
//
//Record current solution(for later backtracks)
//		Proceed to next column in row(col++)
//		If(col equals 9) {
//		Reset col to 1 (col = 1)
//			Proceed to next row(row++)
//	}
//}


Backtracking::Backtracking()
{
}

Backtracking::Backtracking(Board board)
{
	this->board = board;

	for (int i = 0; i < GRIDSIZE; ++i) //TODO: PUT ALL AREAS INTO A SINGLE ZONE VECTOR
	{
		Zone zt(board, i);
		zones.push_back(zt);
		Column ct(board, i);
		columns.push_back(ct);
		Rows rt(board, i);
		rows.push_back(rt);
	}
}

Backtracking::~Backtracking()
{

}

void Backtracking::solve()
{
	Board backup = board;

	for (int i = 0; i < GRIDSIZE; ++i)
	{
		std::cout << "Zones " << i << ": " << zones[i].CheckAllCellsForCorrect() << zones[i].CheckAllCellsForZero() << std::endl;
		std::cout << "Rows " << i << ": " << rows[i].CheckAllCellsForCorrect() << rows[i].CheckAllCellsForZero() << std::endl;
		std::cout << "Columns " << i << ": " << columns[i].CheckAllCellsForCorrect() << columns[i].CheckAllCellsForZero() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	return;
}
