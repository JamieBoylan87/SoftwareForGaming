#include "Creature.h"

#include <iostream>

Creature::Creature() {

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