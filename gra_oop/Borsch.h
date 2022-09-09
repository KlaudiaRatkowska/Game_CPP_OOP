#pragma once
#include "World.h"
#include "Organism.h"

class Borsch : public Organism {
public:
	Borsch(int x, int y, World* world, int age);
};