#include "WeaponBase.h"
#include "WeaponMelee.h"


WeaponMelee::WeaponMelee(std::string name, int damage, int hitChance, int durability) :WeaponBase("LightSword", 25, 20, 15)
{

}

int WeaponBase::Attack()
{
    m_durabilty -= 1;
    m_damage += 1;
    m_hitChance += 1;
    return m_damage;
}