#pragma once

#include <iostream>

class Weapon
{
private:
	//int m_id{};
protected:
	int m_damage{};
	int m_hitChance{};
	int m_durabilty{};
public:
	std::string m_name{};
	Weapon();
	Weapon(std::string name, int damage, int hitChance, int durability);
	~Weapon() {};
	int Attack();
	//std::string getName();
};
