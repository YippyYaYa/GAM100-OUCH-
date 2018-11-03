#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Grid.h"
#include <windows.h>

enum GameState {
		Loading,
		MainMenu,
		Playing,
		Credits,
		Quit
	};

static enum GameState currentState;

void Game_InitGame();
/*Update game*/
void Game_Update();
void Game_setCurrentState(enum GameState newState);
enum GameState Game_getCurrentState();

#endif GAME_H