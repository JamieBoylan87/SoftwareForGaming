#pragma once

class Player
{

private:
	int map;
	int health;
	int experience;
	int x;
	int y;

public:
	Player();
	void initialise(int map, int health, int experience);

	// Set the character at position xy on the map 
	void setXY(int x, int y);

	// Get the character position
	void getXY(int& x, int& y);
};