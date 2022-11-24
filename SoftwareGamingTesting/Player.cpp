#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Player.h"

using namespace std;

Player::Player()
{
	x = 0;
	y = 0;
}

void Player::initialise(int level, int health, int experience)
{
	level = level;
	health = health;
	experience = experience;
}

void Player::setXY(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Player::getXY(int& _x, int& _y)
{
	_x = x;
	_y = y;
}
