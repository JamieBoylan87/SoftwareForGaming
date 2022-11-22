#include "Weapon.h"


Weapon::Weapon(std::string name, int damage, int hitChance, int durability) :Weapon("BroadSword", 50, 50, 25)
{

}

//Weapon::Weapon(std::string name, int damage, int hitChance, int durability) : Weapon("Dagger", 10, 10, 7)
//{
//
//}
//
//Weapon::Weapon(std::string name, int damage, int hitChance, int durability) : Weapon("LightSword", 25, 20, 15)
//{
//
//}

int Weapon::Attack()
{
    m_durabilty -= 1;
    m_damage += 2;
    m_hitChance += 2;
    return m_damage;
}
