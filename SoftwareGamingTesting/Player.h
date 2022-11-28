#pragma once

class Player
{

private:
	int map;
	int level;
	int _attack;
	int health;
	int shield;
	int experience;
	int x;
	int y;

public:
	Player();
	void initialise(int _map, int level, int _health, int _experience, int _attack, int _shield);

	// Set the character at position xy on the map 
	void setXY(int x, int y);

	// Get the character position
	void getXY(int& x, int& y);
	int getLevel() { return level; }
	int getAttack() { return _attack; }
	int getHealth() { return health; }
	int getShield() { return shield; }
	int getExperience() { return experience; }


	int attack();
	int takeDamage(int attack);
	void addExperience(int _experience);
};