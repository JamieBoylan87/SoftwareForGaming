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
		system("PAUSE");
	}

	string line;
	while (getline(file, line))
	{
		mapData.push_back(line);
	}
	
	file.close();

	char character;
	for (int i = 0; i < mapData.size(); i++)
	{
		for (int j = 0; j < mapData[i].size(); j++)
		{
			character = mapData[i][j];

			switch (character)
			{
			case '@': //Player
				player.setXY(j, i);
				break;
			case 'S': //Snake
				creatures.push_back(Creature("Snake", character, 2, 5, 1, 50, 0));
				creatures.back().setXY(j, i);
				break;
			case 'D':
				creatures.push_back(Creature("Dragon", character, 10, 20, 10, 500, 10));
				creatures.back().setXY(j, i);

			//default:
				//cout << "Unrecognised symbol";
			}
		}
	}
}

void Map::printMap()
{
	system("CLS");

	for (int i = 0; i < mapData.size(); i++)
	{
		printf("%s\n", mapData[i].c_str());
	}
}

void Map::tryMovePlayer(char input, Player &player)
{
	int playerX;
	int playerY;
	player.getXY(playerX, playerY);


	switch (input)
	{
	case 'w':
		movePlayer(playerX, playerY -1 , player);
		break;
	case 'a':
		movePlayer(playerX - 1, playerY, player);
		break;
	case 's':
		movePlayer(playerX, playerY + 1, player);
		break;
	case 'd':
		movePlayer(playerX + 1, playerY, player);
		break;
	}
}

void Map::tryMoveCreature(Player &player, int creatureIndex, int targetX, int targetY)
{
	int playerX;
	int playerY;
	int creatureX;
	int creatureY;

	creatures[creatureIndex].getXY(creatureX, creatureY);
	player.getXY(playerX, playerY);

	char moveTile = getChar(targetX, targetY);

	switch (moveTile) 
	{
	case '.':
		creatures[creatureIndex].setXY(targetX, targetY);
		setChar(creatureX, creatureY, '.');
		setChar(targetX, targetY, creatures[creatureIndex].getChar());
		break;
	case '@':
		attackCreature(player, creatureX, creatureY);
		break;
	case '#':
		break;
	default:
		break;
	}
}

char Map::getChar(int x, int y)
{
	return mapData[y][x];
}

void Map::setChar(int x, int y, char c)
{
	mapData[y][x] = c;
}

void Map::movePlayer(int targetX, int targetY, Player &player)
{
	int playerX;
	int playerY;
	player.getXY(playerX, playerY);

	char moveCharacter = getChar(targetX, targetY);
	switch (moveCharacter)
	{
	case '.':
		player.setXY(targetX, targetY);
		setChar(playerX, playerY, '.');
		setChar(targetX, targetY, '@');
	case '#':
		break;
	default:
		attackCreature(player, targetX, targetY);
		break;
	}
}

void Map::moveCreatures(Player &player)
{
	char aiMove;
	int playerX;
	int playerY;
	int creatureX;
	int creatureY;


	player.getXY(playerX, playerY);
	for (int i = 0; i < creatures.size(); i++) {
		aiMove = creatures[i].getMove(playerX, playerY);
		creatures[i].getXY(creatureX, creatureY);

		switch (aiMove) {
		case 'w':
			tryMoveCreature(player, i, creatureX, creatureY - 1);
			break;
		case 's':

			tryMoveCreature(player, i, creatureX, creatureY + 1);

			break;
		case 'a':
			tryMoveCreature(player, i, creatureX - 1, creatureY);
			break;
		case 'd':
			tryMoveCreature(player, i, creatureX + 1, creatureY);
			break;

		}
	}
}

void Map::attackCreature(Player &player, int targetX, int targetY) {
	int creatureX;
	int creatureY;
	int attackRoll;
	int attackResult;
	int playerX;
	int playerY;
	string creatureName;

	player.getXY(playerX, playerY);


	for (int i = 0; i < creatures.size(); i++) {
		creatures[i].getXY(creatureX, creatureY);
		creatureName = creatures[i].getName();
		if (targetX == creatureX && targetY == creatureY) {
			attackRoll = player.attack();
			cout <<"\nPlayer attacked "<< creatureName << " with a roll of: " << attackRoll <<"\n";
			attackResult = creatures[i].takeDamage(attackRoll);
			cout << creatures[i].getHealth();
			if (attackResult != 0) {
				setChar(targetX, targetY, '.');
				cout << creatureName << " died!\n";

				creatures[i] = creatures.back();
				creatures.pop_back();
				i--;
				system("PAUSE");
				player.addExperience(attackResult);
			}
			attackRoll = creatures[i].attack();
			cout << creatureName << " attacked player with a roll of : " << attackRoll << "\n";

			attackResult = player.takeDamage(attackRoll);

			if (attackResult != 0) {

				setChar(playerX, playerY, 'X');
				cout <<"You died!\n";
				system("PAUSE");

				exit(0);
			}
			system("PAUSE");
		}

	}
}


