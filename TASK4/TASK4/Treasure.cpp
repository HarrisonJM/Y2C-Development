#include "stdafx.h"

#include "Treasure.h"

Treasure::Treasure(int x, int y)
{
	xpos = x;
	ypos = y;
}

Treasure::Treasure()
{

}

void Treasure::setXPos(int newx)
{
	xpos = newx;
}

void Treasure::setYPos(int newy)
{
	ypos = newy;
}

int Treasure::getXPos()
{
	return xpos;
}

int Treasure::getYPos()
{
	return ypos;
}
