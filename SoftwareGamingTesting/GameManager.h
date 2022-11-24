#pragma once
#include "Player.h"
#include "Map.h"
#include <string>


using namespace std;

class GameManager
{
private:
	Player player;
	Map map;
public:
	GameManager(string fileName);

	void startGame();
	void handleInput();

};