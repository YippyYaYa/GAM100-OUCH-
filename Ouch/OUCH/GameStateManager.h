#pragma once

enum GameState {
	Loading,
	MainMenu,
	Playing,
	Credits,
	GameOver,
	Quit
};

void GameStateManager_Init();
void GameStateManager_Update();
void GameStateManager_SetGameState(enum GameState newState);
enum GameState GameStateManager_GetCurrentState();