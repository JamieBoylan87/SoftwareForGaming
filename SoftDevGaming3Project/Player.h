#pragma once

#include "Creature.h"

#include <iostream>

class Player : public Creature
{
private:
    int _level;

    void levelUp();

public:
    std::string name;
    Player();
    Player(std::string name, int maxHP, int attackDamage, int attackChance);
    ~Player()
    {
        std::cout << "\nPlayer " << name << "died " << std::endl;
    }
    void GainXP(int xp);
};