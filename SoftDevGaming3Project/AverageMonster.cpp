#include "Creature.h"
#include "Monster.h"

#include <iostream>


Monster::Monster(std::string name, int maxHP, int attackDamage, int attackChance, int xp) :Creature("Demon", 80, 30, 45, 50) {

	_range = 11;
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

int Creature::GetXP()
{
	return _xp;
}