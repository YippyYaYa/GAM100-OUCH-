#pragma once
#include "Credits.h"
#include "GameStateManager.h"
#include <Windows.h>
#include "Grid.h"
#include <stdio.h>
#include "Colours.h"
#include "Enemy.h"

void Credits_Init()
{
	Colours_ResetColor();
	system("cls");
	Grid_initGrid(12);
	Grid_printGrid();
	Enemy_Init();
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

void Credits_Update()
{
	/* ESC Key Entered */
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		GameStateManager_SetGameState(MainMenu);
	}
}