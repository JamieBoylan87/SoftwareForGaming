#pragma once
#include "Point.h"
#include <string>

class Entity {

protected:
	std::string name;
	Point position;

public:
	Entity(std::string newName, Point position);
	Point getLocation();
};

Entity::Entity(std::string newName, Point position)
{
	position = position;
	name = newName;
}

Point Entity::getLocation()
{
	return position;
}