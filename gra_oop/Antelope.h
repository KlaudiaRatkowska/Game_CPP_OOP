#pragma once
#include "World.h"
#include "Organism.h"

class Antelope : public Organism {
public:
	Antelope(int x, int y, World* world, int age);
};