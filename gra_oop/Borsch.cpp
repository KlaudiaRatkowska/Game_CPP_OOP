#include "Borsch.h"
#include "World.h"
Borsch::Borsch(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 10;
	//this->initiative = 0;
	this->sign = BORSCH;
	this->age = age;
	this->step = 0;
}