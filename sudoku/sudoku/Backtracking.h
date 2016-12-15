#pragma once

#include "Solver.h"

class Backtracking : public Solver
{
private:

public:

	Backtracking();
	Backtracking(Board board);
	~Backtracking();

	void solve();

};
