#pragma once
#include "player.h"
#include <string>
#include <vector>
using namespace std;
class Map
{
private:
	vector <string> levelData;


public:
	Map();

	void loadMap(string fileName, Player &player);
	void printMap();
	void MovePlayer();
};