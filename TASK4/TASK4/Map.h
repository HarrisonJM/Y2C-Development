#pragma once
#ifndef __MAP_H_
#define __MAP_H_

#include "stdafx.h"

#include <vector>

#include "Player.h"
#include "Trap.h"
#include "Treasure.h"

#include "Enemy.h"

class Map
{
private:
	int xMaxSize;
	int yMaxSize;

	int numOfTraps;
	int numOfEnemies;

	std::vector < std::vector<char> > field; //(xMaxSize, std::vector<char>(yMaxSize));

	Treasure treasure;
	std::vector<Trap> traps;

	std::vector<Enemy> enemies;

public:
	Player player;

	Map(int xsize, int ysize, int trpnum, int enenum);

	void MapGenerator();

	void generateTraps();
	void generateEnemies();

	Treasure PlaceTreasure();

	void PlayerMove();

	void RedrawMap(int level);

	void PlayerDied(int oldx, int oldy);

	void MovePlayer(char c);
	void MoveEnemies(int m, int index);
	void EnemiesMove();

};


#endif // !__MAP_H_