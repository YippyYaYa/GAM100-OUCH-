#pragma once
#include "MainMenu.h"
#include "GameStateManager.h"
#include <Windows.h>
#include "Grid.h"
#include <stdio.h>

static const int KEY_UP = 0x1;
static enum Selected currentSelected;

void MainMenu_Init()
{
	system("cls");
	currentSelected = MenuPlay;
	Grid_initGrid(0);
	Grid_printGrid();

}
void MainMenu_Update()
{
	if ((GetAsyncKeyState(VK_LEFT) &KEY_UP) == KEY_UP && currentSelected != MenuPlay)
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
	else if ((GetAsyncKeyState(VK_RIGHT) &KEY_UP) == KEY_UP && currentSelected != MenuCredits)
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
	else if ((GetAsyncKeyState(VK_RETURN) &KEY_UP) == KEY_UP)
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

/* function definitions here */