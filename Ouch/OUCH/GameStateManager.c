/******************************************************************************/
/*!
\file   GameStateManager.c
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the functions to control the game states
*/
/******************************************************************************/

#pragma once
#include "GameStateManager.h" /* Function Declarations */
#include "Game.h"             /* Game Functions */
#include "Loading.h"          /* Loading screen */
#include "MainMenu.h"         /* Main Menu */
#include "Credits.h"          /* Credits */
#include "Score.h"            /* Score */
#include "GameOver.h"         /* Game Over */

static enum GameState currentState; /* Store current game stage */

/* Initial state set to loading */
void GameStateManager_Init()
{
	currentState = Loading;
	GameStateManager_SetGameState(Loading);
}

/* Calls update loop of the current state */
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
	case Score:
		Score_Update(dt);
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
	case Score:
		Score_Init();
		break;
	}
}

enum GameState GameStateManager_GetCurrentState()
{
	return currentState;
}

void GameStateManager_RestartLevel()
{
	currentState = Playing;
	Game_LoadLevel(0);
}

void GameStateManager_NextLevel()
{
	currentState = Playing;
	Game_LevelComplete();
}