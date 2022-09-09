#define _CRT_SECURE_NO_WARNINGS 
#include "World.h"
#include "Organism.h"
#include "Human.h"
#include "Wolf.h"
#include "Grass.h"
#include "Antelope.h"
#include "Turtle.h"
#include "Fox.h"
#include "Sheep.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Wolfberries.h"
#include "Borsch.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

World::World(const int width, const int height, vector<Organism*> org)
{
	this->width = width;
	this->height = height;

	map = new Organism ** [width];
	for (int i = 0; i < width; i++)
	{
		map[i] = new Organism * [height];
	}

	for (int i = 0; i < width; i++) 
	{
		for (int j = 0; j < height; j++) 
		{
			map[i][j] = NULL;
		}
	}

	cout << "Organisms take up 30% of area" << endl;
	amountOfOrg = width * height * 3 / 10;
	//vector<Organism*> org;
	int x = rand() % width;
	int y = rand() % height;
	Organism* newOrg = new Human(x, y, this, 0);//creating and placing human on map
	org.push_back(newOrg); 
	SetOrganism(x, y, newOrg);

	int chooseOrg;
	for (int i = 0; i < (amountOfOrg - 1); i++) //crating and placing organisms on map
	{
		int x = rand() % width;
		int y = rand() % height;
		if (map[x][y] == NULL)
		{
			chooseOrg = rand() % AMOUNT_OF_ORGANISMS;  //without human and grass
			switch (chooseOrg)
			{
			case 0:
			{
				newOrg = new Wolf(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			case 1:
			{
				newOrg = new Antelope(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			case 2:
			{
				newOrg = new Turtle(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			case 3:
			{
				newOrg = new Fox(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			case 4:
			{
				newOrg = new Sheep(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			case 5:
			{
				newOrg = new Dandelion(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			case 6:
			{
				newOrg = new Guarana(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			case 7:
			{
				newOrg = new Wolfberries(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			case 8:
			{
				newOrg = new Borsch(x, y, this, 0);
				SetOrganism(x, y, newOrg);
				break;
			}
			}
			org.push_back(newOrg);
		}
		else 
		{
			i--;
		}		
	}
	round = 1;
	
	
	plantGrass(); //rest of area is grass

	printMap();

	playRound(org);
}

void World::playRound(vector<Organism*> org) {
	while (org[0]->GetAge() >= 0) {

		HumanMoves(org[0]);

		for (int i = 1; i < org.size(); i++) {
			Organism* Organism = org[i];
			if (org[i]->GetAge() == DEAD_ORG) {
				cout << "Organism: " << org[i]->GetSign() << " whose coordinates were x: " << org[i]->GetXcoor() << " y: " << org[i]->GetYcoor() << " is dead" << endl;
				org.erase(org.begin() + i);
			}
			else {
				if (org[i]->GetStep() > 0) { //animals
					org[i]->moveOrganisms(map);
				}
				else {
					org[i]->PlantsActions();
				}
				int age = org[i]->GetAge();
				org[i]->SetAge(++age);
			}
		}
		printMap();
	}
}


World::World() {

}

void World::createMap() {
	map = new Organism * *[width];
	for (int i = 0; i < width; i++)
	{
		map[i] = new Organism * [height];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			map[i][j] = NULL;
		}
	}

	plantGrass();
}


void World::SetOrganism(int x, int y, Organism* org)
{
	this->map[x][y] = org;
}

void World::deleteOld(COORDINATES coor)
{
	this->map[coor.x][coor.y] = NULL;
}

void World::plantGrass() {
	for (int i = 0; i < width; i++) //rest of area is grass
	{
		for (int j = 0; j < height; j++)
		{
			if (map[i][j] == NULL)
			{
				Organism* newOrg = new Grass(i, j, this, 0);
				SetOrganism(i, j, newOrg);
			}
		}
	}
}

void World::PlantGrassAfterMove(COORDINATES coor) {
	Organism* grass = new Grass(coor.x, coor.y, this, 0);
	SetOrganism(coor.x, coor.y, grass);
}

void World::printMap() {
	int l = 0;
	cout << "  ";
	for (int k = 0; k < width; k++) {
		if (k % 10 == 0 && k >0)
			l++;
		cout << l;
	}
	cout << endl;
	cout << "  ";
	for (int k = 0; k < width; k++)
		cout << k % 10;

	cout << endl;

	for (int i = 0; i < width; i++)
	{
		if (i < 10)
			cout << " " << i;
		else
			cout << i;

		for (int j = 0; j < height; j++)
		{
			cout << map[i][j]->GetSign();
		}
		cout << endl;
	}
}

void World::HumanMoves(Organism* human) {
	cout << "						" << endl;
	cout << "ROUND: " << round << endl;
	Human* Hum = (Human*)human;
		int x = Hum->GetXcoor();
		int y = Hum->GetYcoor();
		if (x == NULL && y == NULL) {
	cout << "Human does not exist - game over" << endl;
	exit(1);
	}
	else {
	cout << "Human coordinates are: " << "x: " << x << " y: " << y << endl;
	cout << "Make move using button:" << endl;
	cout << "	- W -> go up" << endl;
	cout << "	- S -> go down" << endl;
	cout << "	- A -> go left" << endl;
	cout << "	- D -> go right" << endl;
	cout << "Press Q if you want to finish current game" << endl;
	cout << "Press X if you want to save game" << endl;
	}
		Hum->MakeOperation();
		round++;
}

const int World::GetHeight() {
	return height;
}

const int World::GetWidth() {
	return width;
}

Organism* World::GetArea(COORDINATES coordinates) {
	return map[coordinates.x][coordinates.y];
}

World::~World() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			delete map[i][j];
	}
	for (int i = 0; i < height; i++) {
		delete[] map[i];
	}
	delete[] map;

	cout << endl;
	cout << "GAME OVER";
}

char* World::ReadFileName() {
	system("CLS");
	string name;
	cout << "Enter file name: ";
	cin >> name;
	name += ".txt";
	int n = name.length();
	char* nameArr = new char[n + 1];
	strcpy(nameArr, name.c_str());
	return nameArr;
}

void World::LoadInfoFromFile() {
	char* file = ReadFileName();
	FILE* fptr;
	fptr = fopen(file, "r");
	if (fptr == NULL) {
		cout << "Error";
		exit(1);
	}

	char info[50] = {};
	fgets(info, 50, fptr);
	int j = 0;
	this->height = GetValueFromChar(info, &j);
	this->width = GetValueFromChar(info, &j);
	this->round = GetValueFromChar(info, &j);
	this->amountOfOrg = GetValueFromChar(info, &j);

	if (height > 0 && width > 0 && round > 0) {
		createMap();
		LoadOrganisms(fptr);

		cout << "World loaded sucessfully" << endl;
		printMap();
	}
	fclose(fptr);

	playRound(org);
}

int World::GetValueFromChar(char* sign, int* iterator)
{
	int result = 0, i = 0;
	while (sign[*iterator + i] >= 48 && sign[*iterator + i] <= 57)
	{
		result = result * 10 + (sign[*iterator + i] - 48);
		i++;
	}
	*iterator += 1 + i;
	return result;
}

void World::LoadOrganisms(FILE* fptr) {
	char infoOrg[50] = {};
	while (fgets(infoOrg, 50, fptr) != NULL) {

		if (infoOrg[0] != '/')
		{
			char species = infoOrg[0];

			int i = 2;
			int x = GetValueFromChar(infoOrg, &i);
			int y = GetValueFromChar(infoOrg, &i);
			int age = GetValueFromChar(infoOrg, &i);

			if (x >= width || y >= height) {
				cout << "Incorrect position ";
				if (x >= width) cout << "x ";
				if (y >= height) cout << "y ";
				cout << "of one of organisms" << endl;
				exit(1);
			}


			Organism* Org = CreateSpecies(species, x, y, age);

			if (Org == NULL) {
				std::cout << "Incoorect organisms name";
				exit(1);
			}
			else {

				if (map[x][y]->GetSign() != GRASS) 
					cout << "Area " << x << " " << y << " is occupied by " << map[x][y]->GetSign() << endl;
				else 
					cout << "New organism: " << species << "  coordinated x: " << x << " y: " << y << "  of age: " << age << endl;
			}
		}
	}
}

Organism* World::CreateSpecies(char species, int x, int y, int age) {
	Organism* newOrg = NULL;
	switch (species) {
	case WOLF:
	{
		newOrg = new Wolf(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case ANTELOPE:
	{
		newOrg = new Antelope(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case TURTLE:
	{
		newOrg = new Turtle(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case FOX:
	{
		newOrg = new Fox(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case SHEEP:
	{
		newOrg = new Sheep(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case DANDELION:
	{
		newOrg = new Dandelion(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case GUARANA:
	{
		newOrg = new Guarana(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case WOLFBERRIES:
	{
		newOrg = new Wolfberries(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case BORSCH:
	{
		newOrg = new Borsch(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case HUMAN:
	{
		newOrg = new Human(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	case GRASS:
	{
		newOrg = new Grass(x, y, this, 0);
		SetOrganism(x, y, newOrg);
	}break;
	}
	return newOrg;
}

void World::SaveInFile() {
	ofstream fileToSave;
	fileToSave.open("backUp.txt", ios::out);
	if (fileToSave)
	{
		fileToSave << width << " " << height << " " << round << amountOfOrg << "\n";
		for (auto orgOnMap : org) {
			if (orgOnMap->GetSign() != GRASS) {
				fileToSave << orgOnMap->GetSign() << " " << orgOnMap->GetXcoor() << " " << orgOnMap->GetYcoor() << " " << orgOnMap->GetAge() << "\n";

				cout << "saved " << orgOnMap->GetSign() << " " << orgOnMap->GetXcoor() << " " << orgOnMap->GetYcoor() << " " << orgOnMap->GetAge() << "\n";
			}
		}

		system("CLS");
		cout << "Game saved in file backUp.txt" << endl;
		fileToSave.close();
	}
	else {
		std::cout << "Error - game not saved" << endl;;
		exit(1);
	}
}