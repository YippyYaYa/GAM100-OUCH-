#pragma once
#include "Enemy.h"
#include "Grid.h"
#include "GameStateManager.h"
#include "WindowsHelper.h"
#include <stdio.h>

struct Enemy enemy[3];
static int i;

void Enemy_init(int array, int posX, int posY, char direction, char symbol)
{
	enemy[array].posX = posX;
	enemy[array].posY = posY;
	enemy[array].direction = direction;
	enemy[array].symbol = symbol;
	enemy[array].activated = 'Y';
	Grid_setGrid(posX, posY, symbol);
}

void Enemy_Update()
{
	/*need delta time*/
	for (i = 0; i < 3; i++)
	{
		if (enemy[i].activated == 'Y')
		{
			if (enemy[i].direction == 'U')
			{
				if (Grid_getGrid(enemy[i].posX, enemy[i].posY - 1) != '#')
				{
					WindowsHelper_SetCursorPosition(enemy[i].posX, enemy[i].posY);
					printf("%c", ' ');
					enemy[i].posY--;
					Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].symbol);
					WindowsHelper_SetCursorPosition(enemy[i].posX, enemy[i].posY);
					printf("%c", enemy[i].symbol);
				}
				else
					enemy[i].direction = 'D';
			}
			if (enemy[i].direction == 'D')
			{
				if (Grid_getGrid(enemy[i].posX, enemy[i].posY + 1) != '#')
				{
					Grid_setGrid(enemy[i].posX, enemy[i].posY, ' ');
					WindowsHelper_SetCursorPosition(enemy[i].posX, enemy[i].posY);
					printf("%c", ' ');
					enemy[i].posY++;
					Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].symbol);
					WindowsHelper_SetCursorPosition(enemy[i].posX, enemy[i].posY);
					printf("%c", enemy[i].symbol);
				}
				else
					enemy[i].direction = 'U';
			}
			if (enemy[i].direction == 'L')
			{
				if (Grid_getGrid(enemy[i].posX - 1, enemy[i].posY) != '#')
				{
					Grid_setGrid(enemy[i].posX, enemy[i].posY, ' ');
					WindowsHelper_SetCursorPosition(enemy[i].posX, enemy[i].posY);
					printf("%c", ' ');
					enemy[i].posX--;
					Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].symbol);
					WindowsHelper_SetCursorPosition(enemy[i].posX, enemy[i].posY);
					printf("%c", enemy[i].symbol);
				}
				else
					enemy[i].direction = 'R';
			}
			if (enemy[i].direction == 'R')
			{
				if (Grid_getGrid(enemy[i].posX + 1, enemy[i].posY) != '#')
				{
					Grid_setGrid(enemy[i].posX, enemy[i].posY, ' ');
					WindowsHelper_SetCursorPosition(enemy[i].posX, enemy[i].posY);
					printf("%c", ' ');
					enemy[i].posX++;
					Grid_setGrid(enemy[i].posX, enemy[i].posY, enemy[i].symbol);
					WindowsHelper_SetCursorPosition(enemy[i].posX, enemy[i].posY);
					printf("%c", enemy[i].symbol);
				}
				else
					enemy[i].direction = 'L';
			}
		}
	}
}