#pragma once
#ifndef __TREASURE_H_
#define __TREASURE_H_

#include "stdafx.h"

class Treasure
{
private:
	int xpos;
	int ypos;

public:
	Treasure(int x, int y);
	Treasure();

	void setXPos(int newx);
	void setYPos(int newy);

	int getXPos();
	int getYPos();

};


#endif // !__TREASURE_H_
