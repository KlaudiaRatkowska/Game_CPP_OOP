#include "Antelope.h"
#include "World.h"

Antelope::Antelope(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 4;
	this->initiative = 4;
	this->sign = ANTELOPE;
	this->age = age;
	this->step = 2;
}

