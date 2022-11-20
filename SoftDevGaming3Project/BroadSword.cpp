#include "WeaponBase.h"
#include "WeaponMelee.h"


WeaponMelee::WeaponMelee(std::string name, int damage, int hitChance, int durability) :WeaponBase("BroadSword", 50, 50, 25)
{

}

int WeaponBase::Attack()
{
    m_durabilty -= 1;
    m_damage += 2;
    m_hitChance += 2;
    return m_damage;
}
