#pragma once
#include <string>
#include "Player.h"

using namespace std;

class Creature
{
private:
	//Name of creature e.g Dragon
	string name;
	//Character associated with creature
	char character;
	//Damage that the creature can do to player
	int _attack;
	//Health of creature
	int health;
	//Max Damage that creature can absorb
	int shield;
	//Experience that the creature will drop when it dies
	int experience;
	//How often the creature will wonder - Lower = more often, Higher - less often
	int speed;
	//Position coordinates
	int x;
	int y;
public:
	//Constructor
	Creature(string _name, char _characterm, int attack, int _health, int _shield, int _experience, int _speed);
	// Set the character at position xy on the map 
	void setXY(int x, int y);
	// Get the position of creature
	void getXY(int& x, int& y);
	// Gets the character associated with creature
	char getChar() { return character; }
	// Gets the creatures health
	int getHealth() { return health; }
	//Gets the creatures name
	string getName();

	//Removes players damage from health
	int takeDamage(int attack);
	//Gets the random generated damage that the creatures attack does to player between 0 and _attack
	int attack();
	//Movement AI
	char getMove(int playerX, int playerY);

};