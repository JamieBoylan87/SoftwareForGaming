#pragma once

#include "Creature.h"

#include <iostream>

class AverageMonster : public Creature
{
private:

public:
    std::string name;
    AverageMonster(std::string name, int maxHP, int attackDamage, int attackChance, int xp);
    ~AverageMonster()
    {
        std::cout << "\nMonster " << name << " destoyed" << std::endl;
    }
};