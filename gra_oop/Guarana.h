#pragma once
#include "World.h"
#include "Organism.h"

class Guarana : public Organism {
public:
	Guarana(int x, int y, World* world, int age);
};