#pragma once
#include "World.h"
#include "Organism.h"

class Dandelion : public Organism {
public:
	Dandelion(int x, int y, World* world, int age);
};