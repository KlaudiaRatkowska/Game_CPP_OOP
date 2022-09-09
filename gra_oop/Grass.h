#pragma once
#include "World.h"
#include "Organism.h"

class Grass : public Organism {
public:
	Grass(int x, int y, World* world, int age);
};