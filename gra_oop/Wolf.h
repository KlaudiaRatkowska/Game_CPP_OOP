#pragma once
#include "World.h"
#include "Organism.h"

class Wolf : public Organism {
public:
	Wolf(int x, int y, World* world, int age);
};
