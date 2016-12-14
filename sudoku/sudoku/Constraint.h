#pragma once

#include "Board.h"
#include "Cell.h"

class Constraint
{
private:


public:
	Constraint();
	~Constraint();

	void Solve(Board board);
};
