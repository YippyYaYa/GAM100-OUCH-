#include "Grid.h"
#include <stdio.h>
#include "WindowsHelper.h"
#define N 100

int i, j;
char grid[N][N] = { '0' };

/*Store grid, will upgrade to file i/o*/
void Grid_initGrid()
{
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			grid[i][j] = '#';
	}
}

/*Prints the grid*/
void Grid_printGrid()
{
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