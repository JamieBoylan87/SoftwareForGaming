#pragma once

#include "Creature.h"

#include <iostream>

class SmallMonster : public Creature
{
private:

public:
    std::string name;
    SmallMonster(std::string name, int maxHP, int attackDamage, int attackChance, int xp);
    ~SmallMonster()
    {
        std::cout << "\nMonster " << name << " destoyed" << std::endl;
    }
};