#include "stdafx.h"
#include "Enemy.h"

#include <random>

Enemy::Enemy(int x, int y)
{
	xpos = x;
	ypos = y;
}

Enemy::Enemy()
{
}

int Enemy::Move()
{
	int movement = rand() % 5;

	return movement;
}

void Enemy::kill()
{
	alive = 0;
}

void Enemy::resurrect()
{
	alive = 1;
}

bool Enemy::getLiving()
{
	return alive;
}

int Enemy::getXPos()
{
	return xpos;
}

int Enemy::getYPos()
{
	return ypos;
}

void Enemy::setXPos(int x)
{
	xpos = x;
}

void Enemy::setYPos(int y)
{
	ypos = y;
}

