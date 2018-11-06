#pragma once
#include "Enemy.h"
#include "Grid.h"
#include "GameStateManager.h"
#include "WindowsHelper.h"
#include <stdio.h>

struct Enemy enemy[3];
static int i;

void Enemy_Init(int array, float posX, float posY, char direction, char symbol, float velocity)
{
	enemy[array].posX = posX;
	enemy[array].posY = posY;
	enemy[array].direction = direction;
	enemy[array].symbol = symbol;
	enemy[array].activated = 'Y';
	enemy[array].oldGrid = Grid_getGrid((int)posX, (int)posY);
	enemy[array].velocity = velocity;
	Grid_setGrid((int)posX, (int)posY, symbol);
}

void Enemy_Kill(int posX, int posY)
{
	for (i = 0; i < 3; i++)
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

void Enemy_Update(float dt)
{
	for (i = 0; i < 3; i++)
	{
		if (enemy[i].activated == 'Y')
		{
			if (enemy[i].direction == 'U')
			{
				if (Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY - 1) != '#')
				{
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY));
					enemy[i].posY -= enemy[i].velocity * dt;
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
				if (Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY + 1) != '#')
				{
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY));
					enemy[i].posY += enemy[i].velocity * dt;;
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
				if (Grid_getGrid((int)enemy[i].posX - 1, (int)enemy[i].posY) != '#')
				{
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY));
					enemy[i].posX -= enemy[i].velocity * dt;;
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
				if (Grid_getGrid((int)enemy[i].posX + 1, (int)enemy[i].posY) != '#')
				{
					Grid_setGrid((int)enemy[i].posX, (int)enemy[i].posY, enemy[i].oldGrid);
					WindowsHelper_SetCursorPosition((int)enemy[i].posX, (int)enemy[i].posY);
					printf("%c", Grid_getGrid((int)enemy[i].posX, (int)enemy[i].posY));
					enemy[i].posX += enemy[i].velocity * dt;;
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