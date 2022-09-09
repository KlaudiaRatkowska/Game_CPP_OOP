#include "Fox.h"
#include "World.h"
Fox::Fox(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 3;
	this->initiative = 7;
	this->sign = FOX;
	this->age = age;
	this->step = 1;
}