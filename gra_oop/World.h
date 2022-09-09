#pragma once
#include <vector>
#include "Organism.h"
#include "Human.h"

class Organism;

class World {
private:
	int width, height;
	int round;
	int amountOfOrg;
	Organism*** map;
	
public:
	World();
	World(const int width, const int height, vector<Organism*> org);
	void playRound(vector<Organism*> org);
	void SetOrganism(int x, int y, Organism* org);
	void plantGrass();
	void printMap();
	void HumanMoves(Organism* human);
	const int GetHeight();
	const int GetWidth();
	Organism* GetArea(COORDINATES coordinates);
	vector<Organism*> org;
	void PlantGrassAfterMove(COORDINATES coor);
	void deleteOld(COORDINATES coor);
	void LoadInfoFromFile();
	char* ReadFileName();
	int GetValueFromChar(char* sign, int* iterator);
	void createMap();
	void LoadOrganisms(FILE* fptr);
	Organism* CreateSpecies(char species, int x, int y, int age);
	void SaveInFile();
	~World();
};

