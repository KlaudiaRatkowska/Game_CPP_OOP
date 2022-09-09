#include "Wolfberries.h"
#include "World.h"
Wolfberries::Wolfberries(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 99;
	//this->initiative = 0;
	this->sign = WOLFBERRIES;
	this->age = age;
	this->step = 0;
}