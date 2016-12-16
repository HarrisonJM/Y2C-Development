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
		Row rt(board, i);
		rows.push_back(rt);
	}

	fillMap();
}

Backtracking::~Backtracking()
{

}

void Backtracking::fillMap()
{
	vector<vector<Cell>> b = board.getBoard();
	int index = 0;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (b[i][j].getCellVal() == 0)
			{
				Cell cell(i, j);
				this->gaps[index] = cell;
				++index;
			}
		}
	}
}

void Backtracking::Solve()
{
	vector<vector<Cell>> backup = board.getBoard();
	
	for (int i = 0; gaps.size(); ++i) //for each false position
	{
		for (int j = gaps[i].getCellVal(); j < 10;) //start couting from last value used because previous didn't work
		{
			while(UpdateCell(++j, gaps[i].getxPos(), gaps[i].getyPos(), &backup))
			{
				if (j > 9) //maximum value
				{
					i -= 2; //step two steps back, i will be incremented when for loop exit
					UpdateCell(0, gaps[i].getxPos(), gaps[i].getyPos(), &backup);
					break;
				}
			}
		}

		board.updateBoard(backup);
	}

	return;
}

bool Backtracking::UpdateCell(int value, int col, int rw, vector<vector<Cell>> *b) //returns true if number invalid
{
	int backup = b->at(rw).at(col).getCellVal();
	Board ig;

	//columns
	columns.at(col).AccessCells(rw, NULL).setCellVal(value);
	if (columns.at(col).CheckAllCellsForCorrect() == 0)
	{
		return true;
	}

	//rows
	rows.at(rw).AccessCells(col, NULL).setCellVal(value);
	if (rows.at(rw).CheckAllCellsForCorrect() == 0)
	{
		return true;
	}

	//zones
	zones.at(ig.FindZone(rw, col)).AccessCells(rw, col);
	if (zones[ig.FindZone(rw, col)].CheckAllCellsForCorrect())
	{
		return true;
	}

	//generic board
	b->at(rw).at(col).setCellVal(value);

	return false;

}




