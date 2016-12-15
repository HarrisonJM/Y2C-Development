#include "Cell.h"

Cell::Cell()
{

}

Cell::~Cell()
{

}

Cell::Cell(int val)
{
	this->cellVal = val;
}

int Cell::getCellVal()
{
	return cellVal;
}

void Cell::setCellVal(int val)
{
	cellVal = val;
}

int * Cell::ReturnPossVal()
{
	return nullptr;
}
