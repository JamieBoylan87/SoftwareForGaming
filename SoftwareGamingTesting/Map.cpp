#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map()
{

}

void Map::loadMap(string fileName, Player &player)
{
	ifstream file;

	file.open(fileName);
	if (file.fail())
	{
		cout << fileName << " failed!";
	}

	string line;
	while (getline(file, line))
	{
		levelData.push_back(line);
	}

	char character;
	for (int i = 0; i < levelData.size(); i++)
	{
		for (int j = 0; j < levelData[i].size(); j++)
		{
			character = levelData[i][j];

			switch (character)
			{
			case '@':
				player.setXY(j, i);
				break;
			default:
				cout << "Unrecognised symbol"
			}
		}
	}
}

void Map::printMap()
{
	cout << string(100, '\n');

	for (int i = 0; i < levelData.size(); i++)
	{
		cout << levelData[i] << '\n';
	}
}

void Map::MovePlayer()
{

}