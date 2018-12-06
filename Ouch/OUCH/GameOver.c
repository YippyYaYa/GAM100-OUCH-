/******************************************************************************/
/*!
\file   GameOver.c
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the initialisation and updating for gameover screen
*/
/******************************************************************************/

#pragma once
#include "GameOver.h"         /* Function Declarations */
#include "Grid.h"             /* For initialising of game over screen */
#include "GameStateManager.h" /* For changing state */
#include <stdio.h>            /* For printf */
#include "Colours.h"          /* For printing in colour */
#include "WindowsHelper.h"    /* Set cursor position */

static int currentStage;

/* Initialise game over screen */
void GameOver_Init() 
{
	system("cls");
	currentStage = 8;
	Grid_initGrid(currentStage);
	/*Print Grid and Etc*/
	Grid_printGrid();
	WindowsHelper_SetCursorPosition(38, 23);
	printf("Press enter to try again\n");
	WindowsHelper_SetCursorPosition(35, 24);
	printf("Or ESC to return to main menu");
	Enemy_Init();
}

/* Update Loop */
void GameOver_Update() 
{
	/*pass in enter*/
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		/* change state accordingly */
		GameStateManager_RestartLevel();
	}
	else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		GameStateManager_SetGameState(MainMenu);
	}
}