#include "Creature.h"

#include <iostream>


Creature::Creature(std::string name, int maxHP, int attack, int xp) {

    this->name = name;
    _maxHP = maxHP;
    _hp = _maxHP;
    _attack = attack;
    _xp = xp;
}


void Creature::TakeDamage(int damage) {

    _hp -= damage;

    std::cout << name << " lost " << damage << " hp\t [ " << _hp << " | " << _maxHP << " ]\n";
}


int Creature::Attack() {
    return _attack;
}

bool Creature::isAlive() {
    return _hp > 0;
}

int Creature::GetXP() {
    return _xp;
}