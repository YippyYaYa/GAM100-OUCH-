/******************************************************************************/
/*!
\file   MainMenu.c
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the functions for main menu
*/
/******************************************************************************/

#pragma once
#include "MainMenu.h"         
#include "GameStateManager.h" 
#include "Grid.h"             
#include "Colours.h"          
#include "Enemy.h"           

static enum Selected currentSelected;

/* Initilise */
void MainMenu_Init()
{
	Colours_ResetColor();
	system("cls");
	currentSelected = MenuPlay;
	Grid_initGrid(0);
	Grid_printGrid();
	Enemy_Init();
}

/* Update Loop */
void MainMenu_Update()
{
	/* Left Key entered */
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && currentSelected != MenuPlay)
	{
		if (currentSelected == MenuQuit)
		{
			Grid_initGrid(0);
			Grid_printGrid();
			currentSelected = MenuPlay;
		}
		else if (currentSelected == MenuCredits)
		{
			Grid_initGrid(10);
			Grid_printGrid();
			currentSelected = MenuQuit;
		}
	}
	/* Right Key entered */
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && currentSelected != MenuCredits)
	{
		if (currentSelected == MenuPlay)
		{
			Grid_initGrid(10);
			Grid_printGrid();
			currentSelected = MenuQuit;
		}
		else if (currentSelected == MenuQuit)
		{
			Grid_initGrid(11);
			Grid_printGrid();
			currentSelected = MenuCredits;
		}
	}
	/* Enter key entered */
	else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (currentSelected == MenuPlay)
		{
			GameStateManager_SetGameState(Playing);
		}
		else if (currentSelected == MenuCredits)
		{
			GameStateManager_SetGameState(Credits);
		}
		else if (currentSelected == MenuQuit)
		{
			GameStateManager_SetGameState(Quit);
		}
	}
}