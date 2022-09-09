#pragma once
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
using namespace std;

#define HUMAN 'H'
#define WOLF 'W'
#define SHEEP 'S'
#define FOX 'F'
#define TURTLE 'T'
#define ANTELOPE 'A'

#define GRASS '_'
#define DANDELION 'D' 
#define GUARANA 'G'
#define WOLFBERRIES 'R' 
#define BORSCH 'B'

#define AMOUNT_OF_ORGANISMS 9 //without human and grass

#define GO_UP 87
#define GO_DOWN 83
#define GO_LEFT 65
#define GO_RIGHT 68
#define ENTER 13
#define GAME_OVER 81
#define TAB 9

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define DEAD_ORG -1

#define SAVE 88
#define QUIT 81

#define SPECIAL_SKILL 5

struct COORDINATES {
	int x;
	int y;
};

enum DIRECTION {
	UP_DIR,
	DOWN_DIR,
	LEFT_DIR,
	RIGHT_DIR,
	NO_DIR
};

class Swiat;

