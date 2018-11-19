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
	Colours_SetColor(RED);
	currentStage = 8;
	Grid_initGrid(currentStage);
	/*Print Grid and Etc*/
	Grid_printGrid();
	Colours_ResetColor();
	WindowsHelper_SetCursorPosition(38, 23);
	printf("Press enter to try again\n");
	WindowsHelper_SetCursorPosition(35, 24);
	printf("Or ESC to return to main menu");
}

void GameOver_Update() 
{
	/*pass in enter*/
	if (GetKeyState(VK_RETURN) & 0x8000)
	{
		/* change state accordingly */
		GameStateManager_RestartLevel();
	}
	else if (GetKeyState(VK_ESCAPE) & 0x8000)
	{
		GameStateManager_SetGameState(MainMenu);
	}
}