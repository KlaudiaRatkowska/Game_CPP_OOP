#pragma once
#include "Defines.h"
//#include "World.h"
class World;

class Organism {
protected:
	World* world;
	char sign;
	int strength;
	int initiative;
	int age;
	int x;
	int y;
	int step = 1;

public:
	void SetSign(char sign);
	const char GetSign();
	void SetXcoor(int x);
	void SetYcoor(int y);
	void SetAge(int age);
	void SetStrength(int strength);
	int GetXcoor();
	int GetYcoor();
	int GetAge();
	int GetStep();
	int GetStrength();
	void moveOrganisms(Organism*** map);
	void collision();
	void multiplicate(Organism*** map, COORDINATES coordinates);
	void ReturnToStartingPosition(DIRECTION direction);
	bool NewOrgArea(COORDINATES *newAnimalCoor, COORDINATES coor);
	void createNewOrg(char sign, COORDINATES newAnimalCoor);
	void PlantsActions();
};
