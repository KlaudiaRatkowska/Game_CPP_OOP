#include "Guarana.h"
Guarana::Guarana(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->strength = 0;
	//this->initiative = 0;
	this->sign = GUARANA;
	this->age = age;
	this->step = 0;
}