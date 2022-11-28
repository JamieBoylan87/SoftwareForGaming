#include "Creature.h"
#include <random>
#include <iostream>


Creature::Creature(string _name, char _character, int attack, int _health, int _shield, int _experience, int _speed)
{
	name = _name;
	character = _character;
	_attack = attack;
	health = _health;
	shield = _shield;
	experience = _experience;
	speed = _speed;
}

void Creature::setXY(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Creature::getXY(int& _x, int& _y)
{
	_x = x;
	_y = y;
}

string Creature::getName()
{
	return name;
}


int Creature::attack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);
	return attackRoll(randomEngine);
}

int Creature::takeDamage(int damage) 
{
	damage -= shield;
	if (damage > 0) {
		health -= damage;
		if (health <= 0) 
		{
			return experience;

		}
	}
	return 0;
}

char Creature::getMove(int playerX, int playerY)
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 3 + speed);


	int distance;
	int dx = x - playerX;
	int dy = y - playerY;
	int adx = abs(dx);
	int ady = abs(dy);
	distance = adx + ady;

	//You can change 5 if you want
	if (distance <= 5) {
		//Moving along X axis
		if (adx > ady) {
			if (dx > 0) {
				return 'a';
			}
			else {
				return 'd';
			}
		}
		else { //Move along Y axis
			if (dy > 0) {
				return 'w';
			}
			else {
				return 's';
			}
		}
	}

	int randomMove = moveRoll(randomEngine);

	switch (randomMove) {
	case 0:
		return 'a';
	case 1:
		return 'w';
	case 2:
		return 's';
	case 3:
		return 'd';
	default:
		return '.';
	}
}