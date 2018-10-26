#include "Grid.h"
#include <stdio.h>
#include "WindowsHelper.h"
#define N 10

int i, j;
FILE*textart;				/*create a variable to store file*/
char grid[N][N] = { '0' };	/*define a 2D array by size NxN*/
char name[] = "test.txt";	/*take in file name, needs more work*/

/*Stores grid, need switch/ifelse statements for file level variable intake(name will be hardcoded)*/
void Grid_initGrid()
{
	
	/*open file for reading*/
	fopen_s(&textart, name, "r");
	/*Transverse 2D array*/
	for(i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			/*stores char in file to grid and checks if char in file is newline, if true, re-scan to grid*/
			if ((grid[i][j] = getc(textart)) == '\n')
				j--;
		}
	}
	/*close file*/
	fclose(textart);
}

/*Prints the grid*/
void Grid_printGrid()
{
	/*Set cursor position to 0,0*/
	WindowsHelper_SetCursorPosition(0, 0);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

/*Get grid element*/
char Grid_getGrid(int x, int y)
{
	return grid[x][y];
}

/*Set grid element*/
void Grid_setGrid(int x, int y, char z)
{
	grid[x][y] = z;
}