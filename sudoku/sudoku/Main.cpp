
#include "Board.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	string fileName;
	Board board;

	fileName = "sudoku.txt";	
	board.populateBoard(fileName, board);

}