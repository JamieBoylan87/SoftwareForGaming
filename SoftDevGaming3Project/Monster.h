#pragma once

#include "Creature.h"

#include <iostream>

class Monster : public Creature
{
private:

public:
    std::string name;
    Monster(std::string name, int maxHP, int attackDamage, int attackChance, int xp);
    ~Monster()
    {
        std::cout << "\nMonster " << name << " destoyed" << std::endl;
    }
};