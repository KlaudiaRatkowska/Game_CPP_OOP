#include "Organism.h"
#include "World.h"
#include "Fox.h"
#include "Antelope.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Wolf.h"
#include "Dandelion.h"

void Organism::SetSign(char sign) {
	this->sign = sign;
}

void Organism::SetXcoor(int x) {
	this->x = x;
}

void Organism::SetYcoor(int y) {
	this->y=y;
}

const char Organism::GetSign() {
	return sign;
}

int Organism::GetXcoor() {
	return x;
}

int Organism::GetYcoor() {
	return y;
}

int Organism::GetAge() {
	return age;
}

int Organism::GetStep() {
	return step;
}

int Organism::GetStrength() {
	return strength;
}

void Organism::SetAge(int age) {
	this->age = age;
}

void Organism::SetStrength(int strength) {
	this->strength = strength;
}


void Organism::moveOrganisms(Organism*** map) {
	cout << endl;
	cout << "Organism: " << sign << " of age: " << age << " and coordinates x: " << x << " y: " << y << " is changing its position" << endl;
	bool positionNotChanged = true;
	DIRECTION direction = NO_DIR;
	COORDINATES coordinates2, coor, startingCoor;
	startingCoor.x = x;
	startingCoor.y = y;
	int chancesToMove = 10;
	while (positionNotChanged && chancesToMove) {
		int dir = rand() % 4;
		switch (dir) 
		{
		case UP: {
			if (x - step >= 0) 
			{
				this->SetXcoor(x - step); //change coordinates
				positionNotChanged = false;
				direction = UP_DIR;
			}
		}
			   break;
		case DOWN: {
			if (x + step < world->GetHeight()) {
				this->SetXcoor(x + step);
				positionNotChanged = false;
				direction = DOWN_DIR;
			}
		}
				 break;
		case LEFT: {
			if (y - step >= 0) {
				this->SetYcoor(y - step);
				positionNotChanged = false;
				direction = LEFT_DIR;
			}
		}
				 break;
		case RIGHT: {
			if (y + step < world->GetWidth()) {
				this->SetYcoor(y + step);
				positionNotChanged = false;
				direction = RIGHT_DIR;
			}
		}
				  break;
		}
		chancesToMove--;
	} 
	coor.x = x;
	coor.y = y;
	if (direction == NO_DIR) {
		cout << "This organism did not move" << endl;
	}
	else {
		if (world->GetArea(coor)->GetSign() != GRASS) //there is other organism in this area
		{
			if (map[x][y]->GetSign() == this->GetSign()) { //there is the same spiecies - parent2
				coordinates2.x = x; //parent2' coordinates
				coordinates2.y = y;
				this->ReturnToStartingPosition(direction); //parent1 changes coordinates
				this->multiplicate(map, coordinates2); //create new orgianism of the same spiecies nearby
			}
			else { //there is other species
				if (map[x][y]->GetStrength() < this->GetStrength()) { //other oragnism is weaker
					cout << "This organisms fought with organism " << map[x][y]->GetSign() << " and won" << endl;
					cout << "Its new coordinates are x: " << x << " y: " << y << endl;
					if (map[x][y]->GetSign() == GUARANA) {
						int strength = this->GetStrength();
						this->SetStrength(strength + 3);
					}
					if (map[x][y]->GetSign() == WOLFBERRIES) {
						cout << "OOppss, it was wolfberries - animal die" << endl;
						world->PlantGrassAfterMove(coor);
					}
					if (map[x][y]->GetSign() == HUMAN) {
						map[x][y]->SetAge(DEAD_ORG);
					}
					world->SetOrganism(x, y, this);
					world->PlantGrassAfterMove(startingCoor);
				}
				else { //other organism is stronger
					cout << "This organisms fought with organism " << map[x][y]->GetSign() << " and lost" << endl;
					cout << "This organism died" << endl;
					this->SetAge(DEAD_ORG);
					world->PlantGrassAfterMove(coor);
				}
			}
		}

		else {
			cout << "Its new coordinates are x: " << x << " y: " << y << endl;  //animal moved
			world->SetOrganism(x, y, this);
			world->deleteOld(startingCoor);
			world->PlantGrassAfterMove(startingCoor);
			cout << endl;
		}
	}
}





void Organism::multiplicate(Organism*** map, COORDINATES coordinates) {
	COORDINATES newAnimalCoor;
	if (this->NewOrgArea(&newAnimalCoor, coordinates)) { //there is place for new organism
		createNewOrg(sign, newAnimalCoor);
		cout << "This organism has multiplied and did not change its coordinates" << endl;
		cout << "New organisms' coordinates are x: " << newAnimalCoor.x << " y: " << newAnimalCoor.y << endl;
		cout << endl;
	}
	else {
		cout << "This organism tried to multiply but failed and has not changed its coordinates" << endl;
		cout << endl;
	}


}

void Organism::ReturnToStartingPosition(DIRECTION direction) {
	if (direction == UP_DIR)
		this->SetYcoor(x + step);
	if (direction == DOWN_DIR)
		this->SetYcoor(x - step);
	if (direction == LEFT_DIR)
		this->SetXcoor(y + step);
	if (direction == RIGHT_DIR)
		this->SetXcoor(y - step);
}

bool Organism::NewOrgArea(COORDINATES *newAnimalCoor, COORDINATES coor) {
	bool newArea = false;
	for (int i = (coor.y - 1); i <= (coor.y + 1); i++) {
		for (int j = (coor.x - 1); j <= (coor.x - 1); j++) {
			coor.y = i;
			coor.x = j;
			if (i >= 0 && i < world->GetHeight() && j >= 0 && j < world->GetWidth()) {
				if (world->GetArea(coor)->GetSign() == GRASS) {
					newAnimalCoor->x = j;
					newAnimalCoor->y = i;
					newArea = true;
					return newArea;
				}
			}
		}
	}
		return newArea;
}

void Organism::createNewOrg(char sign, COORDINATES newAnimalCoor){
	Organism* newOrg;
	switch (sign) {
	case WOLF:
	{
		newOrg = new Wolf(newAnimalCoor.x, newAnimalCoor.y, world, 0);
		world->SetOrganism(newAnimalCoor.x, newAnimalCoor.y, newOrg);
	}break;
	case ANTELOPE:
	{
		newOrg = new Antelope(newAnimalCoor.x, newAnimalCoor.y, world, 0);
		world->SetOrganism(newAnimalCoor.x, newAnimalCoor.y, newOrg);
	}break;
	case TURTLE:
	{
		newOrg = new Turtle(newAnimalCoor.x, newAnimalCoor.y, world, 0);
		world->SetOrganism(newAnimalCoor.x, newAnimalCoor.y, newOrg);
	}break;
	case FOX:
	{
		newOrg = new Fox(newAnimalCoor.x, newAnimalCoor.y, world, 0);
		world->SetOrganism(newAnimalCoor.x, newAnimalCoor.y, newOrg);
	}break;
	case SHEEP:
	{
		newOrg = new Sheep(newAnimalCoor.x, newAnimalCoor.y, world, 0);
		world->SetOrganism(newAnimalCoor.x, newAnimalCoor.y, newOrg);
	}break;
	}

	world->org.push_back(newOrg);
}

void Organism::PlantsActions() {
	COORDINATES coor;
	if (sign == DANDELION) { //has three chances to disper
		for (int i = 0; i < 3; i++) {
			int x_rand = rand() % 3;
			int y_rand = rand() % 3;
			coor.x = x - 1 + x_rand;
			coor.y = y - 1 + y_rand;
			if (coor.x >= 0 && coor.x < world->GetHeight() && coor.y >= 0 && coor.y < world->GetWidth()) {
				if (world->GetArea(coor)->GetSign() == GRASS) {
					Organism* dandelion = new Dandelion(coor.x, coor.y, world, 0);
					world->SetOrganism(coor.x, coor.y, dandelion);
				}
			}
		}
	}

	if (sign == BORSCH) { //kills all organisms nearby
		for (int j = (x - 1); j <= (x + 1); j++) {
			for (int i = (y - 1); i <= (y + 1); i++) {
				coor.x = j;
				coor.y = i;
				if (i >= 0 && i < world->GetWidth() && j >=0 && j < world->GetHeight()) {
					if (world->GetArea(coor)->GetSign() != GRASS && world->GetArea(coor)->GetSign() != BORSCH) {
						cout << "Borsch " << x << " " << y << " killed organism: " << world->GetArea(coor)->GetSign() << " coordinated : x: " << coor.x << " y: " << coor.y << endl;
						if (world->GetArea(coor)->GetSign() == HUMAN) {
							exit(1);
						}
						world->GetArea(coor)->SetAge(DEAD_ORG);
						world->PlantGrassAfterMove(coor);
					}
				}
			}
		}
	}
}