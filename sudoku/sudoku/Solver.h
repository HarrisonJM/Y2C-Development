#pragma once

#include "Board.h"
#include "Zone.h"
#include "column.h"
#include <vector>

using namespace std;

class Solver
{
public:
	Board board;
	vector<Zone> zones;
	vector<Column> columns;

private:
};