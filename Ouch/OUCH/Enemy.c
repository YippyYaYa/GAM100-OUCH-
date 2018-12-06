/******************************************************************************/
/*!
\file   Enemy.c
\author Chew Wei Fa Alex
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
Enemy.c is in charge of managing the enemies spawned in the game.
*/
/******************************************************************************/
#pragma once
#include "Enemy.h"

static struct Enemy enemy[ENEMY_ARRAY_SIZE]; /*Maximum array size of enemy*/
static int i; /*Variable to transverse array*/
static int activatedEnemies; /*Size of array of enemies spawned*/
static float move = 0.0f; /*Checks whether to update or not*/

/*Initialise enemy*/
void Enemy_Init()
{
	for (i = 0; i < ENEMY_ARRAY_SIZE; i++)
	{
		enemy[i].activated = 'N';
		enemy[i].direction = 'X';
		enemy[i].velocity = 0;
	}
	activatedEnemies = 0;
}

/*Spawns enemy - takes in position, direction, symbol, and velocity*/
void Enemy_Spawn(int posX, int posY, char direction, char symbol, float velocity)
{
	for (i = 0; i < ENEMY_ARRAY_SIZE; i++)
	{
		if (enemy[i].activated == 'N')
		{
			enemy[i].posX = posX;
			enemy[i].posY = posY;
			enemy[i].direction = direction;
			enemy[i].symbol = symbol;
			enemy[i].oldGrid = Grid_getGrid(posX, posY);
			enemy[i].velocity = velocity;
			Grid_setGrid(posX, posY, symbol);
			enemy[i].activated = 'Y';
			activatedEnemies += 1;
			break;
		}
	}
}

/*Kills the enemy and prints old grid*/
void Enemy_Kill(int posX, int posY)
{
	for (i = 0; i < activatedEnemies; i++)
	{
		if (enemy[i].posX == posX)
		{
			if (enemy[i].posY == posY)
			{
				enemy[i].activated = 'N';
				Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].oldGrid);
			}
		}
	}
}

/*Update enemy movement*/
void Enemy_Update(float dt)
{
	for (i = 0; i < activatedEnemies; i++)
	{
		enemy[i].move = enemy[i].move + enemy[i].velocity * dt;
		if (enemy[i].move > 1)
		{
			enemy[i].move = 0;
			if(enemy[i].activated == 'Y')
			{
				if (enemy[i].direction == 'U') /*if direction is 'U'*/
				{
					if (Collision_Check(enemy[i].posX, enemy[i].posY - 1) == 0 &&
						Collision_Enemy(enemy[i].posX, enemy[i].posY - 1) == 0)
					{
						/*Set current position to old grid before moving - same for other directions*/
						Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].oldGrid);
						/*Change player position - same for other directions*/
						enemy[i].posY -= 1;
						/*Store next grid into old grid for use - same for other directions*/
						enemy[i].oldGrid = Grid_getGrid(enemy[i].posX, enemy[i].posY);
						Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].symbol);
					}
					else
						enemy[i].direction = 'D';
				}
				else if (enemy[i].direction == 'D') /*if direction is 'D'*/
				{
					if (Collision_Check(enemy[i].posX, enemy[i].posY + 1) == 0 &&
						Collision_Enemy(enemy[i].posX, enemy[i].posY + 1) == 0)
					{
						Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].oldGrid);
						enemy[i].posY += 1;
						enemy[i].oldGrid = Grid_getGrid(enemy[i].posX, enemy[i].posY);
						Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].symbol);
					}
					else
						enemy[i].direction = 'U';
				}
				else if (enemy[i].direction == 'L')
				{
					if (Collision_Check(enemy[i].posX - 1, enemy[i].posY) == 0 &&
						Collision_Enemy(enemy[i].posX - 1, enemy[i].posY) == 0)
					{
						Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].oldGrid);
						enemy[i].posX -= 1;
						enemy[i].oldGrid = Grid_getGrid(enemy[i].posX, enemy[i].posY);
						Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].symbol);
					}
					else
						enemy[i].direction = 'R';
				}
				else if (enemy[i].direction == 'R')
				{
					if (Collision_Check(enemy[i].posX + 1, enemy[i].posY) == 0 &&
						Collision_Check(enemy[i].posX + 1, enemy[i].posY) == 0)
					{
						Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].oldGrid);
						enemy[i].posX += 1;
						enemy[i].oldGrid = Grid_getGrid(enemy[i].posX, enemy[i].posY);
						Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].symbol);
					}
					else
						enemy[i].direction = 'L';
				}
			}
		}
	}
}
