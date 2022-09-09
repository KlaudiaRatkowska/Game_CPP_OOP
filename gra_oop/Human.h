#pragma once
#include "World.h"
#include "Organism.h"


class World;

class Human : public Organism {
private:
	int specialSkill;
public:
	Human(int x, int y, World* world, int age);
	int GetXcoor();
	int GetYcoor();
	void MakeOperation();
	void SpecialSkill();
};

