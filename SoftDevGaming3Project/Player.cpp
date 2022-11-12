#include "Creature.h"
#include "Player.h"

Player::Player(std::string name, int maxHP, int attack) :Creature(name, maxHP, attack, 0)
{
    _level = 0;
}

void Player::GainXP(int xp) {
    _xp += xp;

    std::cout << "Received " << xp << " experience points\n";
    // level up every 100 xp points
    if (_xp > 100)
    {
        levelUp();
        _xp -= 100;
    }

}

void Player::levelUp() {
    _level++;
    _attack += 10;

    _maxHP += 10;
    _hp = _maxHP;

    std::cout << "\nLevel up!\n";
}