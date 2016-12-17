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

bool Backtracking::UpdateCell(int value, int x, int y, vector<vector<Cell>> *b) //returns true if number invalid
{
	int backup = b->at(y).at(x).getCellVal();
	Board ig;

	//columns
	//columns.at(x).AccessCells(y, NULL).setCellVal(value); //x colomn on row y
	//if (columns.at(x).CheckAllCellsForCorrect() == false) //False = duplicates, true = good
	//{
	//	return true;
	//}
	columns.at(y).AccessCells(x, NULL).setCellVal(value); //x colomn on row y
	if (columns.at(y).CheckAllCellsForCorrect() == false) //False = duplicates, true = good
	{
		return true;
	}
	//rows
	rows.at(y).AccessCells(x, NULL).setCellVal(value);
	if (rows.at(y).CheckAllCellsForCorrect() == false)
	{
		return true;
	}

	//zones
	zones.at(ig.FindZone(x, y)).AccessCells(y, x);
	if (zones[ig.FindZone(x, y)].CheckAllCellsForCorrect() == false)
	{
		return true;
	}

	//generic board
	b->at(y).at(x).setCellVal(value);

	return false;

}




