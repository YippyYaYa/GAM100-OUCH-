#pragma once
#include "MainMenu.h"
#include "GameStateManager.h"
#include <Windows.h>
#include "Grid.h"
#include <stdio.h>

/* variables here, must be static */


void MainMenu_Init()
{
	system("cls");
	Grid_initGrid(7);
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