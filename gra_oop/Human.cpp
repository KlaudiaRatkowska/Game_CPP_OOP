#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <sstream>  
#include <Windows.h>
#include "Human.h"
#include "World.h"
#include "Organism.h"
#include "Grass.h"


Human::Human(int x, int y, World* world, int age) {
	this->x = x;
	this->y = y;
	this->world = world;
	this->sign = HUMAN;
	this->strength = 5;
	this->initiative = 4;
	this->age = age;
	this->step = 1;
	this->specialSkill = 1;
}

int Human::GetXcoor() {
	return x;
}

int Human::GetYcoor() {
	return y;
}

void Human::MakeOperation() {
	char button;
	bool move = true;
	COORDINATES coor, startingCoor;
	startingCoor.x = x;
	startingCoor.y = y;
	cout << "Your move is: " << endl;
	cout << "--------------------------------------------" << endl;

	while (move) {
		cin >> button;
		switch (button)
		{
		case GAME_OVER: {
			cout << "Game over" << endl;
			exit(1);
		}
					  break;
		case GO_UP: {
			if (x - step >= 0) {
				this->x -= 1;
				cout << "Human goes up" << endl;
				move = false;
			}
		}
				  break;
		case GO_DOWN: {
			if (x + step < world->GetHeight()) {
				this->x += 1;
				cout << "Human goes down" << endl;
				move = false;
			}
		}
					break;
		case GO_LEFT: {
			if (y - step >= 0) {
				this->y -= 1;
				cout << "Human goes left" << endl;
				move = false;
			}
		}
					break;
		case GO_RIGHT: {
			if (y + step < world->GetWidth()) {
				this->y += 1;
				cout << "Human goes right" << endl;
				move = false;
			}
		}
					 break;
		case SAVE: {
			world->SaveInFile();
			exit(1);
		} 
				 break;
		default:
			cout << "Incorrect input" << endl;
		}		
	}
	age++;
	coor.x = x;
	coor.y = y;

	if (world->GetArea(coor)->GetSign() != GRASS) //there is other organism in this area
	{
			if (world->GetArea(coor)->GetStrength() < this->GetStrength()) { //other oragnism is weaker
				cout << "Human fought with organism " << world->GetArea(coor)->GetSign() << " and won" << endl;
				cout << "Its new coordinates are x: " << x << " y: " << y << endl;
				world->SetOrganism(x, y, this);
				world->PlantGrassAfterMove(startingCoor);
			}
			else { //other organism is stronger
				cout << "Human fought with organism " << world->GetArea(coor)->GetSign() << " and lost" << endl;
				cout << "Human died" << endl;
				this->SetAge(DEAD_ORG);
			}
		
	}

	else {
		cout << "Humans' new coordinates are x: " << x << " y: " << y << endl;  //animal moved
		world->SetOrganism(x, y, this);
		world->deleteOld(startingCoor);
		world->PlantGrassAfterMove(startingCoor);
		cout << endl;
	}

	if (specialSkill == SPECIAL_SKILL) {
		cout << "Special skill activated: burns area nearby human" << endl;
		SpecialSkill();
		specialSkill = 1;
	}
	else {
		specialSkill++;
	}
}

void Human::SpecialSkill() { //area nearby human is grass
	COORDINATES coor;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			coor.x = this->x - 1 + i;
			coor.y = this->y - 1 + j;
			if (coor.x >= 0 && coor.x < world->GetWidth() && coor.y >= 0 && coor.y < world->GetHeight()) {
				if (world->GetArea(coor)->GetSign() != HUMAN) {
					Organism* org = new Grass(coor.x, coor.y, world, 0);
					world->SetOrganism(coor.x, coor.y, org);
				}
			}
		}
	}
}