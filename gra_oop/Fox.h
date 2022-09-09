#pragma once
#include "World.h"
#include "Organism.h"

class Fox : public Organism {
public:
	Fox(int x, int y, World* world, int age);
};