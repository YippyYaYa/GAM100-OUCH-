/******************************************************************************/
/*!
\file   Loading.c
\author Toh Gim Hsiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
Loading.c is in charge of loading digipen and team logo with colors.
*/
/******************************************************************************/

#pragma once
#include "Loading.h"
#include "GameStateManager.h"
#include <Windows.h>
#include "Grid.h"
#include "Colours.h"

/* variables here, must be static */
static float tPass;
static int count = 0;
void Loading_Init()
{
	/* reset color */
	Colours_ResetColor();
	/* clear screen */
	system("cls");
	/* call grid_initgrid to case 6 */
	Grid_initGrid(6);
	/* call to print grid*/
	Grid_printGrid();
}

void Loading_Update(float dt)
{
	/* time passes over time with delta time */
	tPass = tPass + dt;

	if(count == 0)
    /* if time passed 4 seconds, change state */
	if (tPass > 4.0f)            
	{
		count++;
		/* call for next printgrid */
		Grid_initGrid(7);
		Grid_printGrid();
	}
	/* after time passed 7 secs.. change state ot main menu */
	if(tPass > 7.0f) 
	GameStateManager_SetGameState(MainMenu);
}

/* function definitions here */
void DebugMessage(int index)
{ 
	if (index == 0)
	{
		printf("Success\n");
		printf("this is loading.c debug\n");
		printf("%f\n", tPass);
		printf("%d\n", count);
	}
	/* color.h*/
	else if (index == 1)
	{
		printf("Success\n");
		printf("this is color.h debug\n");
	}
	else if (index == 2)
	{
		printf("Success\n");
		printf("this is window.h debug\n");
	}
	else if (index == 3)
	{
		printf("Success\n");
		printf("this is grid.h debug\n");
	}
	else if (index == 4)
	{
		printf("Success\n");
		printf("finish loading\n");
	}
	else if (index == 5)
	{
		printf("failed\n");
		printf("stuck at loading\n");
	}
}

void DebugMessagewithPosition(int index, int posX, int posY)
{
	if (index == 0)
	{
		WindowsHelper_SetCursorPosition(posX, posY);
		printf("Success\n");
		printf("this is loading.c debug\n");
		printf("%f\n", tPass);
		printf("%d\n", count);
	}
	/* color.h*/
	else if (index == 1)
	{
		WindowsHelper_SetCursorPosition(posX, posY);
		printf("Success\n");
		printf("this is color.h debug\n");
	}
	else if (index == 2)
	{
		WindowsHelper_SetCursorPosition(posX, posY);
		printf("Success\n");
		printf("this is window.h debug\n");
	}
	else if (index == 3)
	{
		WindowsHelper_SetCursorPosition(posX, posY);
		printf("Success\n");
		printf("this is grid.h debug\n");
	}
	else if (index == 4)
	{
		WindowsHelper_SetCursorPosition(posX, posY);
		printf("Success\n");
		printf("finish loading\n");
	}
	else if (index == 5)
	{
		WindowsHelper_SetCursorPosition(posX, posY);
		printf("failed\n");
		printf("stuck at loading\n");
	}
}