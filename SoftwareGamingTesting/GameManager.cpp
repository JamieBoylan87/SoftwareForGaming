#include "GameManager.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

GameManager::GameManager(string fileName)
{
	player.initialise(1, 1, 100, 0, 11, 1);
	map.loadMap(fileName, player);
	map.printMap();
	system("PAUSE");
}

void GameManager::startGame()
{
	bool isDone = false;

	while (isDone != true)
	{
		map.printMap();
		handleInput();
		map.moveCreatures(player);
	}
}

void GameManager::handleInput()
{
	char input;
	printf("\nPlayer stats | Health : %i | Shield : %i | Damage : %i | Level : %i | Experience : %i\n", player.getHealth(), player.getShield(), player.getAttack(), player.getLevel(), player.getExperience());
	input = _getch();
	Sleep(80);

	map.tryMovePlayer(input, player);
}
