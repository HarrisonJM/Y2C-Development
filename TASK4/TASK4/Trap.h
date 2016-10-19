#pragma once
#ifndef __TRAP_H_
#define __TRAP_H_

#include "stdafx.h"

class Trap
{
private:
	int xpos;
	int ypos;

public:
	Trap();
	Trap(int x, int y);


	void setXPos(int newx);
	void setYPos(int newy);

	int getXPos();
	int getYPos();


};


#endif // !__TRAP_H_
