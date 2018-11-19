#pragma once
#include "Credits.h"
#include "GameStateManager.h"
#include <Windows.h>
#include "Grid.h"
#include <stdio.h>
#include "Colours.h"

void Credits_Init()
{
	Colours_ResetColor();
	system("cls");
	Grid_initGrid(12);
	Grid_printGrid();
}

void Credits_Update()
{
	if (GetKeyState(VK_ESCAPE) & 0x8000)
	{
		GameStateManager_SetGameState(MainMenu);
	}
}

/* function declaration here */