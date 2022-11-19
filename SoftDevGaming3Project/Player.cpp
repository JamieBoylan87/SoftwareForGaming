#include "Creature.h"
#include "Player.h"

Player::Player(std::string name, int maxHP, int attackDamage, int attackChance) :Creature("Player", 100, 20, 45, 0)
{
    _level = 1;
}

void Player::GainXP(int xp) {
    _xp += xp;

    std::cout << "Received " << xp << " experience points\n";
    // level up every 100 xp points
    if (_xp >= 100)
    {
        levelUp();
        _xp -= 100;
    }

}

void Player::levelUp() {
    _level++;
    _attackDamage += 10;
    _attackChance += 15;
    _maxHP += 20;
    _hp = _maxHP;

    std::cout << "\nLevel up!\n";
}