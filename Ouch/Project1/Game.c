#include "Game.h"

/*Init game and pass in game level file i/o*/
void Game_InitGame()
{
	Grid_initGrid(1);
	Grid_printGrid();
	Player_InitPlayer();
}

/*Update game*/
void Game_Update()
{
	switch (currentState)
	{
	case Loading:
		break;
	case MainMenu:
		break;
	case Playing:
		Player_Controls();
		break;
	case Credits:
		break;
	}	
}

/* Set current state of game to new state*/
void Game_setCurrentState(enum GameState newState)
{
	currentState = newState;
}

/* Get current state of game*/
enum GameState Game_getCurrentState()
{
	return currentState;
}