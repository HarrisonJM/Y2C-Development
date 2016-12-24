#include "Backtracking.h"
#include <iostream>
#include <string>

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

bool Backtracking::Solve()
{
	vector<vector<Cell>> backup = board.getBoard(); 
	//All of these can be replaced by having an AccessCells() method, 
	//but I wrote those for the others after I started doign this
	
	for (int i = 0; gaps.size(); ++i) //for each false position
	{
		int j = gaps[i].getCellVal(); //start couting from last value used because previous didn't work
		
		while(UpdateCell(++j, gaps[i].getxPos(), gaps[i].getyPos(), &backup)) //only enters loop if false, so if 9 is correct, it breaks
		{ //bugs still exist here
			system("cls");
			board.updateBoard(backup);
			board.PrintBoard();
			
			//cout << endl << endl;
			if (j+1 > 9 || j > 9) //maximum value
			{
				j = 0;
				UpdateCell(0, gaps[i].getxPos(), gaps[i].getyPos(), &backup);
				gaps[i].setCellVal(0);
				i -= 2; //step two steps back, i will be incremented when for loop exit
				break;
			}
		}

		system("cls");
		board.PrintBoard();

		gaps[i].setCellVal(j);

		board.updateBoard(backup);
	}

	return true; //solved!
}

bool Backtracking::UpdateCell(int value, int x, int y, vector<vector<Cell>> *b) //returns true if number invalid
{
	int backup = b->at(y).at(x).getCellVal();
	int posx = FindPos(x);
	int posy = FindPos(y);
	Board ig;

	if (value == 0) //just sets everything to 0 without checks
	{
		columns[x].AccessCells(y, NULL)->setCellVal(value); //x colomn on row y
		rows.at(y).AccessCells(x, NULL)->setCellVal(value); //WORKING!
		zones.at(ig.FindZone(x, y)).AccessCells(posx, posy)->setCellVal(value); //NEXT PART TO CHECK
		b->at(x).at(y).setCellVal(value);

		return false;
	}
	else
	{
		//columns is a vector of colomn. inside their Cells are stored as a single array of colomns
		columns[x].AccessCells(y, NULL)->setCellVal(value); //x colomn on row y
		if (columns.at(x).CheckAllCellsForCorrect() == false) //False = duplicates, true = good
		{
			return true;
		}

		//rows
		rows.at(y).AccessCells(x, NULL)->setCellVal(value); //WORKING!
		if (rows.at(y).CheckAllCellsForCorrect() == false)
		{
			return true;
		}

		//zones
		zones.at(ig.FindZone(x, y)).AccessCells(posx, posy)->setCellVal(value); //NEXT PART TO CHECK
		if (zones[ig.FindZone(posx, posy)].CheckAllCellsForCorrect() == false)
		{
			return true;
		}

		//generic board
		b->at(x).at(y).setCellVal(value);

		return false;
	}

}

int Backtracking::FindPos(int pos)
{
	switch (pos)
	{
	case 0:
	case 1:
	case 2:
		return pos;
		break;
	case 3:
	case 4:
	case 5:
		return pos - 3;
		break;
	case 6:
	case 7:
	case 8:
		return pos - 6;
		break;
	default:
		try
		{
			throw pos;
		}
		catch (int e)
		{
			cout << "Too big. Surpised it dind't out of range!" << e << endl;
		}

	}
	return pos;
}




