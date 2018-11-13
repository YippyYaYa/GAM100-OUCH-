#pragma once
#include "Enemy.h"
#include "Grid.h"
#include "WindowsHelper.h"
#include <stdio.h>
#define ENEMY_ARRAY_SIZE 50

struct Enemy enemy[ENEMY_ARRAY_SIZE];
static int i;
static int activatedEnemies;

static float moveChecker(float velocity, float dt)
{
	velocity * dt;
	if (velocity * dt >= 1)
		return 1;
	else
		return velocity * dt;
}

void Enemy_Init()
{
	for (i = 0; i < ENEMY_ARRAY_SIZE; i++)
	{
		enemy[i].activated = 'N';
	}
	activatedEnemies = 0;
}

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

void Enemy_Kill(int posX, int posY)
{
	for (i = 0; i < activatedEnemies; i++)
	{
		if ((int)enemy[i].posX == posX)
		{
			if ((int)enemy[i].posY == posY)
			{
				enemy[i].activated = 'N';
				activatedEnemies -= 1;
				Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
			}
		}
	}
}

void Enemy_Update(float dt)
{
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
}