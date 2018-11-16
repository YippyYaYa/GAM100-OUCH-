#pragma once
#include "Enemy.h"
#include "Grid.h"
#include "Colours.h"
#include "WindowsHelper.h"
#include <stdio.h>

#define ENEMY_ARRAY_SIZE 50

struct Enemy enemy[ENEMY_ARRAY_SIZE]; /*Maximum array size of enemy*/
static int i; /*Variable to transverse array*/
static int activatedEnemies; /*Size of array of enemies spawned*/

/*Check if velocity*dt exceeded 1 grid - prevents enemy from moving more than 1 grid per update*/
static float moveChecker(float velocity, float dt)
{
	if (velocity * dt >= 1)
		return 1;
	else
		return velocity * dt;
}

/*Initialise enemy*/
void Enemy_Init()
{
	for (i = 0; i < ENEMY_ARRAY_SIZE; i++)
	{
		enemy[i].activated = 'N';
	}
	activatedEnemies = 0;
}

/*Spawns enemy - takes in position, direction, symbol, and velocity*/
void Enemy_Spawn(float posX, float posY, char direction, char symbol, float velocity)
{
	for (i = 0; i < ENEMY_ARRAY_SIZE; i++)
	{
		if (enemy[i].activated == 'N')
		{
			enemy[i].posX = posX;
			enemy[i].posY = posY;
			enemy[i].direction = direction;
			enemy[i].symbol = symbol;
			enemy[i].oldGrid = Grid_getGrid((int)posX, (int)posY);
			enemy[i].velocity = velocity;
			Grid_setGrid((int)posX, (int)posY, symbol);
			enemy[i].activated = 'Y';
			activatedEnemies += 1;
			break;
		}
	}
}

/*Kills the enemy*/
void Enemy_Kill(int posX, int posY)
{
	for (i = 0; i < activatedEnemies; i++)
	{
		if ((int)enemy[i].posX == posX)
		{
			if ((int)enemy[i].posY == posY)
			{
				enemy[i].activated = 'N';
				Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
			}
		}
	}
}

/*Update enemy movement
 
 2*/
void Enemy_Update(float dt)
{
	Colours_SetColor(ENEMY_COLOUR);
	for (i = 0; i < activatedEnemies; i++)
	{
		if (enemy[i].activated == 'Y')
		{
			if (enemy[i].direction == 'U')
			{
				if (Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY - 1) != '#' &&
					Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY - 1) != 'p')
				{
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY));
					enemy[i].posY -= moveChecker(enemy[i].velocity, dt);
					enemy[i].oldGrid = Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY);
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].symbol);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", enemy[i].symbol);
				}
				else
					enemy[i].direction = 'D';
			}
			else if (enemy[i].direction == 'D')
			{
				if (Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY + 1) != '#'&&
					Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY + 1) != 'p')
				{
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY));
					enemy[i].posY += moveChecker(enemy[i].velocity, dt);
					enemy[i].oldGrid = Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY);
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].symbol);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", enemy[i].symbol);
				}
				else
					enemy[i].direction = 'U';
			}
			else if (enemy[i].direction == 'L')
			{
				if (Grid_getGrid((int)enemy[i].posX - 1, (int)enemy[i].posY) != '#' &&
					Grid_getGrid((int)enemy[i].posX - 1, (int)enemy[i].posY) != 'p')
				{
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY));
					enemy[i].posX -= moveChecker(enemy[i].velocity, dt);
					enemy[i].oldGrid = Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY);
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].symbol);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", enemy[i].symbol);
				}
				else
					enemy[i].direction = 'R';
			}
			else if (enemy[i].direction == 'R')
			{
				if (Grid_getGrid((int)enemy[i].posX + 1, (int)enemy[i].posY) != '#' &&
					Grid_getGrid((int)enemy[i].posX + 1, (int)enemy[i].posY) != 'p')
				{
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY));
					enemy[i].posX += moveChecker(enemy[i].velocity, dt);
					enemy[i].oldGrid = Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY);
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].symbol);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", enemy[i].symbol);
				}
				else
					enemy[i].direction = 'L';
			}
		}
	}
		Colours_ResetColor();
}
