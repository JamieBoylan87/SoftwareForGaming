#include "Weapon.h"


int Weapon::Attack()
{
    m_durabilty -= 1;
    m_damage += 2;
    m_hitChance += 2;
    return m_damage;
}
