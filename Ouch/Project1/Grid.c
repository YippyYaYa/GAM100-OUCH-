#include "Grid.h"
#include <stdio.h>
#include "WindowsHelper.h"
#define N 10

int i, j;					/*variable for transversing 2D arrays*/
FILE*textart;				/*create a variable to store file*/
char grid[N][N] = { '0' };	/*define a 2D array by size NxN - all map size must be the same as this, axis is X and Y*/

/*Stores grid from file*/
void Grid_initGrid(int level)
{
	switch (level)
	{
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
			fopen_s(&textart, "level3.txt", "r");
			break;
		case 4:
			/*open file for reading*/
			fopen_s(&textart, "level4.txt", "r");
			break;
		case 5:
			/*open file for reading*/
			fopen_s(&textart, "level5.txt", "r");
			break;
	}
	
	/*Transverse 2D array*/
	for(i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			/*stores char in file to grid array and checks if char in file is newline, if true, re-scan to grid array as we don't wan the newline*/
			if ((grid[j][i] = getc(textart)) == '\n')
				j--;
		}
	}
	/*close file*/
	fclose(textart);
}

/*Prints the initialised grid - probably for printing logos etc*/
void Grid_printGrid()
{
	/*Set cursor position to 0,0*/
	WindowsHelper_SetCursorPosition(0, 0);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			WindowsHelper_SetCursorPosition(j, i);
			printf("%c", grid[j][i]);
		}
	}
}

/*Print initialised grid with player - probably for levels and menus*/
void Grid_printGridwPlayer(int x, int y, char player)
{
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			WindowsHelper_SetCursorPosition(j, i);
			printf("%c", grid[j][i]);
		}
	}
	/*Set cursor position to player position*/
	WindowsHelper_SetCursorPosition(x, y);
	printf("%c", player);
}

/*Get grid element*/
char Grid_getGrid(int x, int y)
{
	return grid[x][y];
}

/*Set grid element - probably wont be used*/
void Grid_setGrid(int x, int y, char z)
{
	grid[x][y] = z;
}