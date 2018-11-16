#pragma once
#include "Grid.h"
#include "Colours.h"
#include "WindowsHelper.h"
#include "CollisionManager.h"
#include <stdio.h>
#define ENEMY_ARRAY_SIZE 50

/*Enemy class initial and final position*/
struct Enemy
{
	int posX;
	int posY;
	char direction;
	char symbol;
	float velocity;
	float move;
	char activated;
	char oldGrid;
};
void Enemy_Init();
/*functions to set enemy positions in grid array*/
void Enemy_Spawn(int posX, int posY, char direction, char symbol, float velocity);
/*moves enemy - to be updated*/
void Enemy_Update(float dt);
void Enemy_Kill(int posX, int posY);