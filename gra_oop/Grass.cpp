#include "Grass.h"
#include "World.h"

Grass::Grass(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 0;
	this->sign = GRASS;
	this->age = age;
	this->step = 0;
}