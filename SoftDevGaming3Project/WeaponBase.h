#pragma once

#include <iostream>

class WeaponBase
{
private:
	//int m_id{};
protected:
	int m_damage{};
	int m_hitChance{};
	int m_durabilty{};
public:
	std::string m_name{};
	WeaponBase(std::string name, int damage, int hitChance, int durability);
	~WeaponBase() {};
	virtual int Attack();
	//std::string getName();
};
