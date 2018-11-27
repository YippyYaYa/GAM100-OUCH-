#pragma once
#include "GameOver.h"
#include "Grid.h"
#include "GameStateManager.h"
#include <stdio.h>
#include <Windows.h>
#include "Colours.h"
#include "WindowsHelper.h"

static int currentStage;

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
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

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