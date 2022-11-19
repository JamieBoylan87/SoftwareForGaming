#pragma once

#include "Creature.h"

#include <iostream>

class BigMonster : public Creature
{
private:

public:
    std::string name;
    BigMonster(std::string name, int maxHP, int attackDamage, int attackChance, int xp);
    ~BigMonster()
    {
        std::cout << "\nMonster " << name << " destoyed" << std::endl;
    }
};