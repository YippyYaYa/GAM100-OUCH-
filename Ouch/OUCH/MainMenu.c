#pragma once
#include "MainMenu.h"
#include "GameStateManager.h"

/* variables here, must be static */

void MainMenu_Init()
{
	system("cls");
}
void MainMenu_Update()
{
	/* do stuff here */

	/* change state accordingly e.g. go to play or credits */
	GameStateManager_SetGameState(Playing);
}

/* function definitions here */