#include "Turtle.h"
#include "World.h"

Turtle::Turtle(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 2;
	this->initiative = 1;
	this->sign = TURTLE;
	this->age = age;
	this->step = 1;
}