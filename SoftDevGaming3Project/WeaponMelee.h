#pragma once

#include "WeaponBase.h"

class WeaponMelee : WeaponBase
{
private:

public:
	WeaponMelee(std::string name, int damage, int hitChance, int durability);
	~WeaponMelee();
	//int Attack();
};