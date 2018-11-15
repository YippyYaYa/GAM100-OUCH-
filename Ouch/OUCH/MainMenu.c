#pragma once
#include "MainMenu.h"
#include "GameStateManager.h"
#include <Windows.h>
#include <stdio.h>

/* variables here, must be static */
static enum GameState currentState;

void MainMenu_Init()
{
	system("cls");
	currentState = 7;
	Grid_initGrid(currentState);
	Grid_printGrid();

}
void MainMenu_Update()
{
	/* do stuff here */
	getchar();
	/* change state accordingly e.g. go to play or credits */
	GameStateManager_SetGameState(Playing);
}

/* function definitions here */