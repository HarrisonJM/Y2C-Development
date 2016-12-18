
#include "Board.h"
#include "Backtracking.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	while (1)
	{
		string fileName;

		//int option;

		cout << "Entire sudoku file name" << endl;
		//cin >> filename;

		fileName = "sudokutester.csv";
		Board board(fileName);

		cout << "1 for backtracking, 2 for constraint, anything else to exit!" << endl;
		//cin >> option;

		board.PrintBoard();

		Backtracking BT(board);
		BT.Solve();
		board = BT.retBoard();
		board.PrintBoard();

		//switch (option)
		//{
		//case 1: //backtracker
		//	break;
		//case 2: //constraint
		//	break;
		//default:
		//	exit(0);
		//	break;
		//}
	}
}