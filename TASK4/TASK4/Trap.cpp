#include "stdafx.h"
#include "Trap.h"

Trap::Trap()
{

}

Trap::Trap(int x, int y)
{
	xpos = x;
	ypos = y;
}


void Trap::setXPos(int newx)
{
	xpos = newx;
}

void Trap::setYPos(int newy)
{
	ypos = newy;
}

int Trap::getXPos()
{
	return xpos;
}

int Trap::getYPos()
{
	return ypos;
}
