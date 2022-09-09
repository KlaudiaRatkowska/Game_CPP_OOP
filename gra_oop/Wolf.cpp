#include "Wolf.h"
#include "Wolf.h"

Wolf::Wolf(int x, int y, World* world, int age)
{
	this->x = x;
	this->y = y;
	this->world = world;
	this->sign = WOLF;
	this->strength = 9;
	this->initiative = 5;
	this->age = age;
	this->step = 1;
}