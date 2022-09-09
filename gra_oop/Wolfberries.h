#pragma once
#include "World.h"
#include "Organism.h"

class Wolfberries : public Organism {
public:
	Wolfberries(int x, int y, World* world, int age);
};