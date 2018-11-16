#pragma once
#include "GameStateManager.h"
#include "Game.h"
#include "Loading.h"
#include "MainMenu.h"
#include "Credits.h"
#include "GameOver.h"
#include <Windows.h>

static enum GameState currentState; /* Store current game stage */

/* Initial state set to loading */
void GameStateManager_Init()
{
	currentState = Loading;
	GameStateManager_SetGameState(Loading);
}

/* Update current state */
void GameStateManager_Update(float dt)
{
	switch(currentState)
	{
	case Loading:
		Loading_Update(dt);
		break;
	case MainMenu:
		MainMenu_Update();
		break;
	case Playing:
		Game_Update(dt);
		break;
	case Credits:
		Credits_Update();
		break;
	case GameOver:
		GameOver_Update();
		break;
	}
}

/* Set new state and calls the init of the new state */
void GameStateManager_SetGameState(enum GameState newState)
{
	currentState = newState;
	switch (currentState)
	{
	case Loading:
		Loading_Init();
		break;
	case MainMenu:
		MainMenu_Init();
		break;
	case Playing:
		Game_Init();
		break;
	case Credits:
		Credits_Init();
		break;
	case GameOver:
		GameOver_Init();
		break;
	}
}

enum GameState GameStateManager_GetCurrentState()
{
	return currentState;
}