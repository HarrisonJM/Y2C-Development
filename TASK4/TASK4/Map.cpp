#include "stdafx.h"

#include <iostream>
#include <random>
#include <vector>
#include <conio.h>

#include "Map.h"

Map::Map(int xsize, int ysize, int trpnum, int enenum)
{
	xMaxSize = xsize;
	yMaxSize = ysize;

	numOfTraps = trpnum;
	numOfEnemies = enenum;

	for (int rows = 0; rows < yMaxSize; rows++)
	{
		field.push_back(std::vector<char>()); //generates rows
	}

	for (int columns = 0; columns < xMaxSize; ++columns)
	{
		for (int rows = 0; rows < yMaxSize; ++rows)
		{
			field[rows].push_back('.'); // Adds columns to all rows
		}
	}

	for (int i = 0; i < numOfTraps; ++i)
	{
		Trap temptrap;

		traps.push_back(temptrap);
	}

	for (int i = 0; i < numOfEnemies; ++i)
	{
		Enemy tempenemy;

		enemies.push_back(tempenemy);
	}

	MapGenerator();
}

void Map::MapGenerator()
{
	//if (enemies.size() > 0)
	//{
	//	for (int i = 0; i < enemies.size(); ++i)
	//	{
	//		enemies.pop_back();
	//	}
	//}

	//if (traps.size() > 0)
	//{
	//	for (int i = 0; i < traps.size(); ++i)
	//	{
	//		traps.pop_back();
	//	}
	//}

	for (int i = 0; i < yMaxSize; ++i)
	{
		for (int j = 0; j < xMaxSize; ++j)
		{
			field[i][j] = '.';
		}
	}

	generateTraps();
	for (int trp = 0; trp < numOfTraps - 1; ++trp) //place traps
	{
		field[traps[trp].getYPos()][traps[trp].getXPos()] = 'T';
	}

	generateEnemies();
	for (int ene = 0; ene < numOfEnemies - 1; ++ene) //place traps
	{
		field[enemies[ene].getYPos()][enemies[ene].getXPos()] = 'V';
	}

	treasure = PlaceTreasure();
	field[treasure.getYPos()][treasure.getXPos()] = 'X';

	field[player.getYPos()][player.getXPos()] = '@';
}

void Map::generateTraps()
{
	for (int i = 0; i < numOfTraps - 1; ++i)
	{
		int x, y;

		do
		{
			x = rand() % xMaxSize - 1;
			y = rand() % yMaxSize - 1;

		} while ((x <= 0) || (y <= 0) || ((x == player.getXPos()) && (y == player.getYPos())));

		traps[i].setXPos(x);
		traps[i].setYPos(y);
	}
}

Treasure Map::PlaceTreasure()
{
	int x, y;

	do
	{
		x = rand() % xMaxSize - 1;
		y = rand() % yMaxSize - 1;

	} while ((x <= 0) || (y <= 0) || ((x == player.getXPos()) && (y == player.getYPos())));

	Treasure temptreas(x, y);

	return temptreas;
}

void Map::generateEnemies()
{
	for (int i = 0; i < numOfEnemies - 1; ++i)
	{
		int x, y;

		do
		{
			x = rand() % xMaxSize - 1;
			y = rand() % yMaxSize - 1;

		} while ((x <= 0) || (y <= 0) || ((x == player.getXPos()) && (y == player.getYPos())));

		enemies[i].setXPos(x);
		enemies[i].setYPos(y);
		enemies[i].resurrect();
	}
}

void Map::PlayerMove()
{
	int level = 1;
	int oldx = player.getXPos(), oldy = player.getYPos();
	char command;

	RedrawMap(level);

	command = _getch();

	MovePlayer(command);

	if (field[player.getYPos()][player.getXPos()] == 'T') //Trap
	{
		PlayerDied(oldx, oldy);
	}
	else if (field[player.getYPos()][player.getXPos()] == 'V') //Enemies
	{
		PlayerDied(oldx, oldy);
	}
	else if (field[player.getYPos()][player.getXPos()] == 'X') //Treasure
	{
		//IncreaseScore NextLevel
		player.setScore(player.getScore() + 1);
		player.CalcHighscore();
		system("cls");
		std::cout << "Congratulations! You got the treasure! Level: " << ++level << std::endl;

		system("pause");
		MapGenerator();
		field[oldy][oldx] = '.';
	}
	else
	{
		field[oldy][oldx] = '.';
		field[player.getYPos()][player.getXPos()] = '@';
	}
}

void Map::EnemiesMove()
{
	for (int i = 0; i < enemies.size() - 1; ++i)
	{
		int oldx = enemies[i].getXPos(), oldy = enemies[i].getYPos();

		if (enemies[i].getLiving())
		{
			MoveEnemies(enemies[i].Move(), i);

			if (field[enemies[i].getYPos()][enemies[i].getXPos()] == 'T') //Trap
			{
				enemies[i].kill();
				field[enemies[i].getYPos()][enemies[i].getXPos()] = '.';
				field[oldy][oldx] = '.';
			}
			else if (field[enemies[i].getYPos()][enemies[i].getXPos()] == 'V') //Enemies
			{				
				enemies[i].setXPos(oldx);
				enemies[i].setYPos(oldy);
			}
			else if (field[enemies[i].getYPos()][enemies[i].getXPos()] == 'X') //Treasure
			{
				enemies[i].setXPos(oldx);
				enemies[i].setYPos(oldy);
			}
			else if (field[enemies[i].getYPos()][enemies[i].getXPos()] == '@') //The player
			{
				PlayerDied(player.getXPos(), player.getYPos());
			}
			else
			{
				field[oldy][oldx] = '.';
				field[enemies[i].getYPos()][enemies[i].getXPos()] = 'V';
			}
		}
	}
}

void Map::RedrawMap(int level)
{
	system("cls");

	std::cout << "Name: " << player.getName() << " Level: " << level << " Score: " << player.getScore() << " HighScore: " << player.getHScore() << std::endl;

	for (int columns = 0; columns < xMaxSize; ++columns)
	{
		for (int rows = 0; rows < yMaxSize; ++rows)
		{
			std::cout << field[rows][columns];
		}

		std::cout << std::endl;
	}

	std::cout << "Press 'P' to quit!" << std::endl;
}

void Map::PlayerDied(int oldx, int oldy)
{
	player.setLiving(0);

	std::cout << "You died! Your score was: " << player.getScore() << " With your current best run being: " << player.getHScore() << std::endl;
	system("pause");

	player.setScore(0);
	player.setXPos(0);
	player.setYPos(0);

	MapGenerator();
	field[oldy][oldx] = '.';
}

void Map::MovePlayer(char c)
{
	int temp;

	switch (c)
	{
	case 'w':
	case 'W':
		temp = player.moveNorth();

		if (temp < 0)
		{
			player.setXPos(xMaxSize - 1);
		}
		break;
	case 'a':
	case 'A':
		temp = player.moveWest();

		if (temp < 0)
		{
			player.setYPos(yMaxSize - 1);
		}
		break;
	case 's':
	case 'S':
		temp = player.moveSouth();

		if (temp >= xMaxSize)
		{
			player.setXPos(0);
		}
		break;
	case 'd':
	case 'D':
		temp = player.moveEast();

		if (temp >= yMaxSize)
		{
			player.setYPos(0);
		}
		break;
	case 'P':
	case 'p':
		std::cout << "Thanks for playing!" << std::endl;
		system("pause");
		exit(0);

		break;
	default:
		break;
	}


}

void Map::MoveEnemies(int m, int index)
{
	int temp;

	switch (m)
	{
	case 0: //north
		temp = enemies[index].getXPos() - 1;

		if (temp < 0)
		{
			enemies[index].setXPos(xMaxSize - 1);
		}
		else
		{
			enemies[index].setXPos(enemies[index].getXPos() - 1);
		}
		break;
	case 1: //west
		temp = enemies[index].getYPos() - 1;

		if (temp < 0)
		{
			enemies[index].setYPos(yMaxSize - 1);
		}
		else
		{
			enemies[index].setYPos(enemies[index].getYPos() - 1);
		}
		break;
	case 2: //south
		temp = enemies[index].getXPos() + 1;

		if (temp >= xMaxSize)
		{
			enemies[index].setXPos(0);
		}
		else
		{
			enemies[index].setXPos(enemies[index].getXPos() + 1);
		}
		break;
	case 3: //east
		temp = enemies[index].getYPos() + 1;

		if (temp >= yMaxSize)
		{
			enemies[index].setYPos(0);
		}
		else
		{
			enemies[index].setYPos(enemies[index].getYPos() + 1);
		}
		break;
	case 4: //don't move

		break;
	default:
		break;
	}
}