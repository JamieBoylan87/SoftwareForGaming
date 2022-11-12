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
    Player(std::string name, int maxHP, int attack);
    // (b)
    ~Player()
    {
        std::cout << "\nDestructor called from: " << name << std::endl;
    }
    void GainXP(int xp);
};