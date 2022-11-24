#include "GameManager.h"
#include <windows.h>

GameManager::GameManager(string fileName)
{
	player.initialise(1, 100, 0);
	map.loadMap(fileName, player);
}

void GameManager::startGame()
{
	bool isDone = false;

	while(isDone != true)
	{
		map.printMap();
		handleInput
	}
}

void GameManager::handleInput()
{

	if ( GetKeyState(VK_UP) & 0x8000)
	{
		if (map.checkXY(newPlayerPositionX, newPlayerPositionY - 1))
		{
			newPlayerPositionY = playerPositionY - 1;
		}
		else
		{
			newPlayerPositionY = playerPositionY;
		}
	}

	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		if (map.checkXY(newPlayerPositionX, newPlayerPositionY + 1))
		{
			newPlayerPositionY = playerPositionY + 1;
		}
		else
		{
			newPlayerPositionY = playerPositionY;
		}
	}

	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (map.checkXY(newPlayerPositionX + 1, newPlayerPositionY))
		{
			newPlayerPositionX = playerPositionX + 1;
		}
		else
		{
			newPlayerPositionX = playerPositionX;
		}
	}

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		if (map.checkXY(newPlayerPositionX - 1, newPlayerPositionY))
		{
			newPlayerPositionX = playerPositionX - 1;
		}
		else
		{
			newPlayerPositionX = playerPositionX;
		}
	}
}