/******************************************************************************/
/*!
\file   Grid.c
\author Chew Wei Fa Alex
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This manager is in charge of processing player controls and actions
*/
/******************************************************************************/
#pragma once
#include "Grid.h"
#include "Enemy.h"
#include <stdio.h>
#include "WindowsHelper.h"
#define X 100
#define Y 25

/*Private variabes*/
static int i, j;					/*private variables for transversing 2D arrays*/
static FILE*textart;				/*create a private variable to store file*/
static char grid[X][Y] = { ' ' };	/*define a 2D array by size NxN - all map size must be the same as this, axis is X and Y*/

/*Stores grid from file*/
void Grid_initGrid(int file)
{
	switch (file)
	{	
	case 0:
		/*open file for reading*/
		fopen_s(&textart, "mainmenu.txt", "r");
		break;
	case 1:
		/*open file for reading*/
		fopen_s(&textart, "level1.txt", "r");
		break;
	case 2:
		/*open file for reading*/
		fopen_s(&textart, "level2.txt", "r");
		break;
	case 3:
		/*open file for reading*/
		fopen_s(&textart, "bear map.txt", "r");
		break;
	case 4:
		/*open file for reading*/
		fopen_s(&textart, "level4.txt", "r");
		break;
	case 5:
		/*open file for reading*/
		fopen_s(&textart, "level5.txt", "r");
		break;
	case 6:
		/*open file for reading*/
		fopen_s(&textart, "DigipenLogo.txt", "r");
		break;
	case 7:
		fopen_s(&textart, "TeamLogo.txt", "r");
		break;
	case 8:
		/*open file for reading*/
		fopen_s(&textart, "Game0ver.txt", "r");
		break;
	case 9:
		/*open file for reading*/
		fopen_s(&textart, "TutorialB.txt", "r");
		break;
	}

	/*Transverse 2D array*/
	for(i = 0; i < Y; i++)
	{
		for (j = 0; j < X;)
		{
			/*stores char in file to grid array and checks if char in file is newline, if true, re-scan to grid array as we don't want the newline*/
			if ((grid[j][i] = (char)getc(textart)) == '\n')
			{
				if (j == 0)
					j--;
				else
				{
					grid[j][i] = ' ';
					i++;
					j = 0;
					continue;
				}
			}
			j++;
		}
	}
	/*close file*/
	fclose(textart);

	if (file == 8)
	{
		for (i = 0; i < Y; i++)
		{
			for (j = 0; j < X; j++)
			{
				grid[j][i] = Ascii(grid[j][i]);
			}
		}
	}
}

/*Prints the initialised grid - probably for printing logos etc*/
void Grid_printGrid()
{
	/*Set cursor position to 0,0*/
	WindowsHelper_SetCursorPosition(0, 0);
	for (i = 0; i < Y; i++)
	{
		/*WindowsHelper_SetCursorPosition(0, i);*/
		for (j = 0; j < X; j++)
		{
			WindowsHelper_SetCursorPosition(j, i);
			printf("%c", grid[j][i]);
		}
		//printf("\n");
	}
}

/*Get grid element*/
char Grid_getGrid(int x, int y)
{
	return grid[x][y];
}

/*Set grid element - will be constantly updating grid for collision detection, use this to push enemies, buttons etc into grid*/
void Grid_setGrid(int x, int y, char z)
{
	grid[x][y] = z;
	WindowsHelper_SetCursorPosition(x, y);
	printf("%c", grid[x][y]);
}