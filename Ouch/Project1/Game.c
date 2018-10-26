#include "Game.h"

/*Init game and pass in game level file i/o*/
void Game_InitGame(int level)
{
	Grid_initGrid();
	Grid_printGrid();
	Player_InitPlayer();
}

/*Update game*/
void Game_Update()
{
	Player_move();
}