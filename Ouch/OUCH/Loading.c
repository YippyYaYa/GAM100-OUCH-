#pragma once
#include "Loading.h"
#include "GameStateManager.h"
#include <Windows.h>
#include <stdio.h>

/* variables here, must be static */

void Loading_Init()
{
	system("cls");
}

void Loading_Update()
{
	/* do stuff here */
	printf("hi");
	/* Change state*/
	GameStateManager_SetGameState(MainMenu);
}

/* function definitions here */