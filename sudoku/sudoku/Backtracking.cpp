#include "Backtracking.h"

//Initialize 2D array with 81 empty cells(9 rows, 9 cols)
//Fill in cells with any known values
//Set this solution as the base solution
//Start from top left cell, row = 1 & col = 1
//while (empty cells exist in solution) {
//	if (cell(row, col) is empty) {
//		assign the empty cell with a valid value(i)
//			// one that does not exists in the same row,
//			// column OR zone as the cell)
//			if (no valid value for (i) can be found) {
//				backtrack to previous solution
//					adjust col and row accordingly
//					remove assigned value from the previously updated cell
//					find another valid value(i) for this cell
//					if no valid value can be found{
//						repeat the backtrack
//					}
//			}
//	}
//	Record current solution(for later backtracks)
//		Proceed to next column in row(col++)
//		If(col equals 9) {
//		Reset col to 1 (col = 1)
//			Proceed to next row(row++)
//	}
//}

Backtracking::Backtracking()
{

}

Backtracking::~Backtracking()
{

}

void Backtracking::solve()
{

}
