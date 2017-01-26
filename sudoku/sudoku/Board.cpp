#include "Board.h"

using namespace std;

Board::Board()
{
	for (int rows = 0; rows < GRIDSIZE; rows++)
	{
		cells.push_back(std::vector<Cell>()); //generates rows
	}

	for (int columns = 0; columns < GRIDSIZE; ++columns)
	{
		for (int rows = 0; rows < GRIDSIZE; ++rows)
		{
			Cell temp(0);
			cells[rows].push_back(temp); // Adds columns to all rows
		}
	}
}

Board::Board(string name)
{
	for (int rows = 0; rows < GRIDSIZE; rows++)
	{
		cells.push_back(std::vector<Cell>()); //generates rows
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

Board::Board(vector<vector<Cell>> b)
{
	this->cells = b;
}

Board::~Board()
{

}

void Board::populateBoard(string name)
{
	//program is a vector of strings, could be cells
	ifstream infile(name);
	string line;
	string c;

	for (int i = 0; i < GRIDSIZE; ++i) //rows
	{
		int j;

		for (j = 0; j < GRIDSIZE-1; j++) //colomuns
		{
			getline(infile, c, ',');
			cells[i][j].setCellVal(stoi(c)); //= stoi(c);
		}
		
		getline(infile, c);
		cells[i][j].setCellVal(stoi(c));
	}

	return;
}

void Board::PrintBoard()
{
	for (int i = 0; i < GRIDSIZE; ++i)
	{
		for (int j = 0; j < GRIDSIZE; ++j)
		{
			cout << "|" << cells[i][j].getCellVal();
		}

		cout << endl;
	}
}

vector<vector<Cell>> Board::getBoard()
{
	return cells;
}

void Board::updateBoard(Board b)
{
	this->cells = b.getBoard();
}

int Board::FindZone(int xpos, int ypos)
{
	//two given values should be for th epositon of the corner of the zone
	int sector =0;

	if (xpos >= 0 && xpos <= 2)
	{
		if (ypos >= 0 && ypos <= 2)
		{
			sector = 0;
		}
		else if (ypos >= 3 && ypos <= 5)
		{
			sector = 1;
		}
		else if (ypos >= 6 && ypos <= 8)
		{
			sector = 2;
		}
	}
	else if (xpos >= 3 && xpos <= 5)
	{
		if (ypos >= 0 && ypos <= 2)
		{
			sector = 3;
		}
		else if (ypos >= 3 && ypos <= 5)
		{
			sector = 4;
		}
		else if (ypos >= 6 && ypos <= 8)
		{
			sector = 5;
		}
	}
	else if (xpos >= 6 && xpos <= 8)
	{
		if (ypos >= 0 && ypos <= 2)
		{
			sector = 6;
		}
		else if (ypos >= 3 && ypos <= 5)
		{
			sector = 7;
		}
		else if (ypos >= 6 && ypos <= 8)
		{
			sector = 8;
		}
	}

	return sector; //returns an index
}

//int(*get_grid())[5]
//{
//	return grid;
//}
