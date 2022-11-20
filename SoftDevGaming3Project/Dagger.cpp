#include "WeaponBase.h"
#include "WeaponMelee.h"


WeaponMelee::WeaponMelee(std::string name, int damage, int hitChance, int durability) :WeaponBase("Dagger", 10, 10, 7)
{
    
}

int WeaponBase::Attack()
{
    m_durabilty -= 1;
    return m_damage;
}

WeaponMelee::~WeaponMelee()
{
    if (m_durabilty == 0)
    {

    }
}