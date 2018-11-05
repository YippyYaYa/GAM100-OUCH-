#pragma once
#include "Game.h"
#include "Grid.h"
#include "Enemy.h"
#include "Player.h"
#include "GameStateManager.h"

/*Init game and pass in game level file i/o*/
void Game_Init()
{
	Grid_initGrid(1);
	Grid_printGridwAll(1);
	Player_InitPlayer();
}

/*Update game*/
void Game_Update()
{
	Player_Controls();
	Enemy_Update();
}