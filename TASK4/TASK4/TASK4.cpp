// TASK4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <random>
#include <iostream>
#include <cstdlib>

#include "Map.h"

#define MAXY 6
#define MAXX 20
#define TRPNUM 7
#define ENEMYNUM 5

void play(Map map);

using namespace std;


int main()
{
	srand(time(NULL));
	string name;

	Map map(MAXY, MAXX, TRPNUM, ENEMYNUM);

	cout << "Please enter your name: ";
	cin >> name;

	map.player.SetName(name);
	system("cls");

	play(map);

    return 0;
}

void play(Map map)
{
	while (1)
	{
		map.PlayerMove();
		map.EnemiesMove();
	}
}

