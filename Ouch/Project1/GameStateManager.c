#pragma once
#include "GameStateManager.h"
#include "Game.h"
#include "Loading.h"
#include "MainMenu.h"
#include "Credits.h"

static enum GameState currentState;

void GameStateManager_Init()
{
	currentState = Loading;
}

void GameStateManager_Update()
{
	switch(currentState)
	{
	case Loading:
		Loading_Update();
		break;
	case MainMenu:
		MainMenu_Update();
		break;
	case Playing:
		Game_Update();
		break;
	case Credits:
		Credits_Update();
		break;
	}
}

void GameStateManager_SetGameState(enum GameState newState)
{
	currentState = newState;
	switch (currentState)
	{
	case MainMenu:
		MainMenu_Init();
		break;
	case Playing:
		Game_Init();
		break;
	case Credits:
		Credits_Init();
		break;
	}
}

enum GameState GameStateManager_GetCurrentState()
{
	return currentState;
}