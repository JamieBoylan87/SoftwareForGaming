#include <windows.h>
#include <iostream>
#include <string>
#include "utility.h"
#include "rogueMap.h"
#include "Creature.h"
#include "Weapon.h"
#include "Player.h"

// map size
#define MAPSIZEX 35
#define MAPSIZEY 25


unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;
char playerChar = 64;

RogueMap map;
//Creature creature;
//Weapon weapon;
//Player player;

void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	if (GetKeyState(0x57) & 0x8000)
	{
		newPlayerPositionY = playerPositionY - 1;
		// call movePlayer(int dirx, int diry);
	}

	if (GetKeyState(0x53) & 0x8000)
	{
		newPlayerPositionY = playerPositionY + 1;
	}

	if (GetKeyState(0x44) & 0x8000)
	{
		newPlayerPositionX = playerPositionX + 1;
	}

	if (GetKeyState(0x41) & 0x8000)
	{
		newPlayerPositionX = playerPositionX - 1;
	}
}

void renderPlayer()
{
	// Draw new player position
	utility::gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << " ";

	// Draw new player position
	utility::gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	// update player position
	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;

	Sleep(120);
}

// print messages below map by moving the cursor 
void renderUI() {
	utility::gotoScreenPosition(0, MAPSIZEY);
	std::cout << "Player: @  Gold: 0  XP: 0\t \tLevel: 1  HP: 100";
}

int main()
{
	//Player player{ "Player", 100, 40, 40 };

	//Creature imp{ "Imp", 20, 15, 20, 35 };

	//Creature demon{ "Demon", 70, 45, 40, 75 };

	//Creature dragon{ "Dragon", 150, 90, 70, 150 };

	//Weapon dagger{ "Dagger", 15, 20, 6 };

	//Weapon lightsword{ "Lightsword", 25, 35,  10 };

	//Weapon broadsword{ "Broadsword", 50, 50, 30 };

	map.loadMap(MAPSIZEX, MAPSIZEY);

	while (true)
	{
		// Handles the input and updates the players position
		handleInput();

		// Render the scene
		renderPlayer();

		// Show messages on the screen
		renderUI();
	}

	return 0;

}