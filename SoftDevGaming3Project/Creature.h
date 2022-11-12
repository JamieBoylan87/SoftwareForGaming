#pragma once

#include <iostream>

class Creature
{
protected:
    int _maxHP;
    int _hp;
    int _attack;
    int _xp;

public:
    std::string name;
    Creature(std::string name, int maxHP, int attack, int xp);
    ~Creature()
    {
        std::cout << "\nDestructor called from: " << name << std::endl;
    };

    int Attack();
    void TakeDamage(int damage);
    bool isAlive();
    int GetXP();
};