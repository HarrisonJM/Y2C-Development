#pragma once
#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "stdafx.h"
#include <string>

class Player
{
private:
	int xpos = 0;
	int ypos = 0;

	std::string name;
	int score = 0;
	int highscore = 0;
	bool alive = 1;

public:
	Player();

	int CalcHighscore();

	int moveNorth();
	int moveEast();
	int moveSouth();
	int moveWest();

	//Getters and setters
	void SetName(std::string s);
	void setScore(int n);
	void setLiving(bool b);

	void setXPos(int newx);
	void setYPos(int newy);

	int getXPos();
	int getYPos();

	std::string getName();
	int getScore();
	int getHScore();
	bool getLiving();

};



#endif //!__PLAYER_H_