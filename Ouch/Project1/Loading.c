#pragma once
#include "Loading.h"
#include "GameStateManager.h"

/* variables here, must be static */

void Loading_Init()
{

}

void Loading_Update()
{
	/* do stuff here */

	/* Change state*/
	GameStateManager_SetGameState(MainMenu);
}

/* function definitions here */