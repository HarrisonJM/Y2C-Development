#pragma once

#include "Board.h"
#include "Zone.h"
#include "Column.h"
#include "Row.h"
#include <vector>

using namespace std;

class Solver
{
public:
	Board board;
	vector<Zone> zones;
	vector<Column> columns;
	vector<Rows> rows;

private:
};