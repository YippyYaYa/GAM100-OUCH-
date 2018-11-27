#pragma once
#include "MainMenu.h"
#include "GameStateManager.h"
#include <Windows.h>
#include "Grid.h"
#include "Colours.h"

static enum Selected currentSelected;

void MainMenu_Init()
{
	Colours_ResetColor();
	system("cls");
	currentSelected = MenuPlay;
	Grid_initGrid(0);
	Grid_printGrid();
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

void MainMenu_Update()
{
	if (GetAsyncKeyState(VK_LEFT) &0x8000 && currentSelected != MenuPlay)
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
	else if (GetAsyncKeyState(VK_RIGHT) &0x8000 && currentSelected != MenuCredits)
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
	else if (GetAsyncKeyState(VK_RETURN) &0x8000)
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