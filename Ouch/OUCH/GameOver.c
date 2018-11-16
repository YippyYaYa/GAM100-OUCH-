#pragma once
#include "GameOver.h"
#include "Grid.h"
#include "GameStateManager.h"
#include <stdio.h>
#include <Windows.h>
#include "Colours.h"

static int currentStage;

void GameOver_Init() 
{
	Colours_SetColor(RED);
	system("cls");
	currentStage = 8;
	Grid_initGrid(currentStage);
	/*Print Grid and Etc*/
	Grid_printGrid();
	Colours_ResetColor();
}

void GameOver_Update() 
{
	int x=38 , y=23;
	WindowsHelper_SetCursorPosition(x, y);
	printf("press enter to try again.");
	/*pass in enter*/
	getchar();
	/* change state accordingly e.g. go to play or credits */
	GameStateManager_SetGameState(Playing);
	
}