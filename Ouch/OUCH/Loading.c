#pragma once
#include "Loading.h"
#include "GameStateManager.h"
#include <Windows.h>
#include <stdio.h>

/* variables here, must be static */
static enum GameState currentState;

void Loading_Init()
{
	system("cls");
	currentState = 0;
	Grid_initGrid(currentState);
	currentState = 1;
	
}

void Loading_Update()
{
	/* do stuff here */
	/* Change state*/
	GameStateManager_SetGameState(MainMenu);
}

/* function definitions here */