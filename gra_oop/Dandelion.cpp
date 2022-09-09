#include "Dandelion.h"
#include "World.h"
Dandelion::Dandelion(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 0;
	//this->initiative = 0;
	this->sign = DANDELION;
	this->age = age;
	this->step = 0;
}