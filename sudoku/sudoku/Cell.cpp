#include "Cell.h"

Cell::Cell()
{

}

Cell::~Cell()
{

}

Cell::Cell(int xpos, int ypos, int val)
{
	this->cellVal = val;
	this->x = xpos;
	this->y = ypos;

	for (int i = 0; i < 8; ++i)
	{
		possVal[i] = 0;
	}
}

int Cell::getCellVal()
{
	return cellVal;
}

void Cell::setCellVal(int val)
{
	cellVal = val;
}

void Cell::AddPossVal(int val)
{
	
}

void Cell::RemovePossVal(int val)
{
}

int * Cell::ReturnPossVal()
{
	return nullptr;
}
