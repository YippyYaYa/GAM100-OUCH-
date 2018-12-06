/******************************************************************************/
/*!
\file   Credits.c
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the initiatisation and update for credits screen
*/
/******************************************************************************/

#pragma once
#include "Credits.h"          /* Function Declarations */
#include "GameStateManager.h" /* To Return to main menu */
#include <Windows.h>          /* For Key Input */
#include "Grid.h"             /* To initialise and print credits screen */   
#include "Enemy.h"            /* To Reset Enemies */

/* Initialise credits screen */
void Credits_Init()
{
	system("cls");
	Grid_initGrid(12);
	Grid_printGrid();
	Enemy_Init();
}

/* Credits Screen update loop */
void Credits_Update()
{
	/* ESC Key Entered */
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		GameStateManager_SetGameState(MainMenu);
	}
}