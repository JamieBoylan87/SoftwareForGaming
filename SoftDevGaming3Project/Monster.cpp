#include "Creature.h"

#include <iostream>


Creature::Creature(std::string name, int maxHP, int attackDamage, int attackChance, int xp) :Creature("imp", 20, 10, 20, 35) {

	_range = 5;
}

//Creature::Creature(std::string name, int maxHP, int attackDamage, int attackChance, int xp):Creature("Demon", 50, 35, 45, 70) {
//
//	_range = 11;
//}
//
//Creature::Creature(std::string name, int maxHP, int attackDamage, int attackChance, int xp) :Creature("Dragon", 150, 65, 70, 200) {
//
//	_range = 20;
//}

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