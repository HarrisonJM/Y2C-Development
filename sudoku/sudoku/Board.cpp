#include "Board.h"

using namespace std;

Board::Board()
{
	for (int rows = 0; rows < GRIDSIZE; rows++)
	{
		cells.push_back(std::vector<int>()); //generates rows
	}

	for (int columns = 0; columns < GRIDSIZE; ++columns)
	{
		for (int rows = 0; rows < GRIDSIZE; ++rows)
		{
			cells[rows].push_back('.'); // Adds columns to all rows
		}
	}
}

Board::Board(string name)
{
	for (int rows = 0; rows < GRIDSIZE; rows++)
	{
		cells.push_back(std::vector<int>()); //generates rows
	}

	for (int columns = 0; columns < GRIDSIZE; ++columns)
	{
		for (int rows = 0; rows < GRIDSIZE; ++rows)
		{
			cells[rows].push_back('.'); // Adds columns to all rows
		}
	}

	populateBoard(name);

	return;
}

Board::~Board()
{

}

void Board::populateBoard(string name)
{
	//program is a vector of strings, chould be cells
	ifstream infile(name);
	string line;
	string c;

	for (int i = 0; i < GRIDSIZE; ++i) //rows
	{
		int j;

		for (j = 0; j < GRIDSIZE-1; j++) //colomuns
		{
			getline(infile, c, ',');
			cells[i][j] = stoi(c);
		}
		
		getline(infile, c);
		cells[i][j] = stoi(c);
	}

	return;
}

void Board::PrintBoard()
{
	for (int i = 0; i < GRIDSIZE; ++i)
	{
		for (int j = 0; j < GRIDSIZE; ++j)
		{
			cout << "|" << cells[i][j];
		}

		cout << endl;
	}
}

vector<vector<int>> Board::getBoard()
{
	return cells;
}

//int(*get_grid())[5]
//{
//	return grid;
//}
