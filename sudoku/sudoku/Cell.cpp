#include "Cell.h"
#include <iostream>

Cell::Cell()
{

}

Cell::~Cell()
{

}

Cell::Cell(int val)
{
	this->cellVal = val;
	this->xpos = 0;
	this->ypos = 0; //if this constructor is calleld we don't care what their positions are
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
	//FINALLY TO HERE
	std::cout << cellVal; //debugging
	this->cellVal = val;
	std::cout << cellVal; //debugging
	std::cout << val; //debugging

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
