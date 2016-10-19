#include "stdafx.h"

#include "Player.h"
#include <string>

Player::Player()
{

}

int Player::CalcHighscore()
{
	if (score > highscore)
	{
		highscore = score;
	}

	return highscore;
}

int Player::moveEast()
{
	ypos++;

	return ypos;
}

int Player::moveWest()
{
	ypos--;

	return ypos;
}

int Player::moveNorth()
{
	xpos--;

	return xpos;
}

int Player::moveSouth()
{
	xpos++;

	return xpos;
}

//Getters and setters
void Player::SetName(std::string s)
{
	name = s;
}

void Player::setScore(int num)
{
	score = num;
}

void Player::setLiving(bool b)
{
	alive = b;
}

void Player::setXPos(int newx)
{
	xpos = newx;
}

void Player::setYPos(int newy)
{
	ypos = newy;
}

int Player::getXPos()
{
	return xpos;
}

int Player::getYPos()
{
	return ypos;
}

std::string Player::getName()
{
	return name;
}

int Player::getScore()
{
	return score;
}

int Player::getHScore()
{
	return highscore;
}

bool Player::getLiving()
{
	return alive;
}

