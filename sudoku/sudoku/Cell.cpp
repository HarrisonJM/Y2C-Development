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

Cell::Cell(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
	this->cellVal = 0;
}

int Cell::getCellVal()
{
	return cellVal;
}

void Cell::setCellVal(int val)
{
	cellVal = val;
}

int Cell::getxPos()
{
	return xpos;
}

void Cell::setxPos(int x)
{
	this->xpos = x;
}

int Cell::getyPos()
{
	return ypos;
}

void Cell::setypos(int y)
{
	this->ypos = y;
}

int * Cell::ReturnPossVal()
{
	return nullptr;
}
