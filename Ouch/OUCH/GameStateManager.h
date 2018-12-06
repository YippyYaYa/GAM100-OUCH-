/******************************************************************************/
/*!
\file   GameStateManager.h
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function declarations for GameStateManager.c
*/
/******************************************************************************/

#pragma once

/* List of game states used */
enum GameState {
	Loading,
	MainMenu,
	Playing,
	Score,
	Credits,
	GameOver,
	Quit
};

void GameStateManager_Init();
void GameStateManager_Update(float dt);
void GameStateManager_SetGameState(enum GameState newState);
enum GameState GameStateManager_GetCurrentState();
void GameStateManager_RestartLevel();
void GameStateManager_NextLevel();