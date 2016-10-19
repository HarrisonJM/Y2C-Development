#pragma once
#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "stdafx.h"

class Enemy
{
private:
	int xpos;
	int ypos;
	bool alive = 1;

public:
	Enemy(int x, int y);

	Enemy();

	int Move();

	void kill();
	void resurrect();

	bool getLiving();

	int getXPos();
	int getYPos();

	void setXPos(int x);
	void setYPos(int y);

};


#endif // !__ENEMY_H_
