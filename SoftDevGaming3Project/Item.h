#include "Entity.h"
#include "Point.h"

class Item : public Entity
{
public:
	Item(std::string name, Point pos);
	void useItem();

};

Item::Item(std::string name, Point pos) :Entity(name, pos)	// Uses parent constructor
{

}

void Item::useItem() {
	std::cout << "Using item...." << std::endl;
}