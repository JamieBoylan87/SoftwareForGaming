#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <random>
#include <ctime>
#include "Player.h"

using namespace std;

Player::Player()
{
	x = 0;
	y = 0;
}

void Player::initialise(int _map, int level, int _health, int _experience, int attack, int _shield)
{
	map = _map;
	health = _health;
	experience = _experience;
	_attack = attack;
	shield = _shield;
}

void Player::setXY(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Player::getXY(int &_x, int &_y)
{
	_x = x;
	_y = y;
}

int Player::attack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackChance(0, _attack);
	return attackChance(randomEngine);
}


int Player::takeDamage(int damage)
{
	damage -= shield;
	if (damage > 0)
	{
		health -= damage;
		if (health <= 0)
		{
			return 1;
		}
		return 0;
	}
	else
	{
		return 0;
	}
}

void Player::addExperience(int _experience)
{
	experience += _experience;

	while (experience > 50)
	{
		experience -= 50;
		_attack += 10;
		shield += 5;
		health += 10;
		level += 1;
		cout << "Leveled up to level " << level << "!\n";
		system("PAUSE");
	}
}
