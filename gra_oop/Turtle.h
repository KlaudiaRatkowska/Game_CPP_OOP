#pragma once
#include "World.h"
#include "Organism.h"


class Turtle : public Organism {
public:
	Turtle(int x, int y, World* world, int age);
};
