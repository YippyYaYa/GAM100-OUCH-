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
#define X 100
#define Y 25

/*Private variabes*/
static int i, j;					/*private variables for transversing 2D arrays*/
static FILE*textart;				/*create a private variable to store file*/
static unsigned char grid[X][Y] = { ' ' };	/*define a 2D array by size NxN - all map size must be the same as this, axis is X and Y*/

/*Stores grid from file*/
void Grid_initGrid(int file)
{
	switch (file)
	{	
	case 0:
		/*open file for reading*/
		fopen_s(&textart, "mainmenuplay.txt", "r");
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
	case 10:
		fopen_s(&textart, "mainmenuquit.txt", "r");
		break;
	case 11:
		fopen_s(&textart, "mainmenucredits.txt", "r");
		break;
	case 12:
		fopen_s(&textart, "credits.txt", "r");
	}

	/*Transverse 2D array*/
	for(i = 0; i < Y; i++)
	{
		for (j = 0; j < X;)
		{
			/*stores char in file to grid array and checks if char in file is newline, if true, re-scan to grid array as we don't want the newline*/
			if ((grid[j][i] = (unsigned char)getc(textart)) == '\n')
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
		for (j = 0; j < X; j++)
		{
			WindowsHelper_SetCursorPosition(j, i);
			if (GameStateManager_GetCurrentState() == Playing && i < 20)
			{
				if (grid[j][i] == 'X')
					/*Colour code for Breakable Wall here*/
					Colours_SetColor(BREAKABLE);
				else if (grid[j][i] == 'p')
					/*Colour code for pushable object here*/
					Colours_SetColor(PUSHABLE);
				else if (grid[j][i] == 'E')
					/*Colour code for exit*/
					Colours_SetColor(END);
			}
			else if (GameStateManager_GetCurrentState() == Loading)
			{
				/*Colour code here*/
				Colours_SetColor(RED);
			}
			else if (GameStateManager_GetCurrentState() == GameOver)
			{
				Colours_SetColor(RED);
			}
			printf("%c", grid[j][i]);
			Colours_ResetColor();
		}
	}
}

/*Get grid element*/
unsigned char Grid_getGrid(int x, int y)
{
	return grid[x][y];
}

/*Set grid element - changes colour if it is portal/switch/enemies,*/
void Grid_setGrid(int x, int y, unsigned char z)
{
	grid[x][y] = z;
	WindowsHelper_SetCursorPosition(x, y);
	if (z == 178 || z == 233 || z == 176)
		/*colour code for portal and switch here*/
		Colours_SetColor(RED);
	else if (z == 'R' || z == 'B')
		/*colour code for enemies here*/
		Colours_SetColor(ENEMY_COLOUR);
	else if (z == 'p')
		/*Colour code for pushable object*/
		Colours_SetColor(PUSHABLE);
	printf("%c", grid[x][y]);
	Colours_ResetColor();
}