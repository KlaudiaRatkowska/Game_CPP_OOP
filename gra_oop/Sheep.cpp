#include "Sheep.h"
#include "World.h"
Sheep::Sheep(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 4;
	this->initiative = 4;
	this->sign = SHEEP;
	this->age = age;
	this->step = 1;
}