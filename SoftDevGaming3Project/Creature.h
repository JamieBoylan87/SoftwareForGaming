#pragma once

#include <iostream>

class Creature
{
protected:
    int _maxHP;
    int _hp;
    int _attackDamage;
    int _attackChance;
    int _range;
    int _rng;
    int _xp;

public:
    std::string name;
    Creature(std::string name, int maxHP, int attackDamage, int attackChance, int xp);
    ~Creature()
    {
       // std::cout << "\nMonster destroyed " << name << std::endl;
    };

    int Attack();
    void TakeDamage(int damage);
    bool isAlive();
    int GetXP();
};