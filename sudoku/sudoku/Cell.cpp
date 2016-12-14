#include "Cell.h"

Cell::Cell()
{
	for (int i = 0; i < 8; ++i)
	{
		possVal[i] = 0;
	}

	//also set up this squares value

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
