#pragma once

#include "Solver.h"

class Backtracking : public Solver
{
private:
	map<int, Cell> gaps;

public:

	Backtracking();
	Backtracking(Board board);
	~Backtracking();

	void fillMap();

	void Solve();

	//bool UpdateCell(int value, int col, int rw);
	bool UpdateCell(int value, int col, int rw, vector<vector<Cell>> *b);

};
