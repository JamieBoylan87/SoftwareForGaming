#pragma once
#include "player.h"
#include <string>
#include <vector>
#include "Creature.h"
using namespace std;
class Map
{
private:
	vector <string> mapData;
	vector <Creature> creatures;

public:
	Map();

	void loadMap(string fileName, Player &player);
	void printMap();
	void tryMovePlayer(char input, Player &player);
	void movePlayer(int targetX, int targetY, Player &player );
	void tryMoveCreature(Player& player, int creatureIndex, int targetX, int targetY);
	void moveCreatures(Player& player);
	void setChar(int x, int y, char c);
	char getChar(int x, int y);
	void attackCreature(Player &player, int targetX, int targetY);
};