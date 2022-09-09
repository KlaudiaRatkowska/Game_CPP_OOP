#pragma once
#include "World.h"
#include "Organism.h"

class Sheep : public Organism {
public:
	Sheep(int x, int y, World* world, int age);
};