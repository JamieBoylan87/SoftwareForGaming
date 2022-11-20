#include "Creature.h"
#include "Monster.h"

#include <iostream>


Monster::Monster(std::string name, int maxHP, int attackDamage, int attackChance, int xp) :Creature("Dragon", 150, 65, 70, 150) {

	_range = 20;
}

void Creature::TakeDamage(int attackDamage)
{
	_hp -= attackDamage;

	std::cout << name << " lost" << "hp\t [ " << _hp << " | " << _maxHP << " ]\n";
}

int Creature::Attack()
{
	_rng = rand() % 100 + 1;
	if (_rng < _attackChance)
	{
		return _attackDamage;
	}
	else 
	{
		return 0;
	};
}

bool Creature::isAlive()
{
	return _hp > 0;
}
